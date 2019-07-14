#include<iostream>
#include<fstream>
using namespace std;
ofstream outfile;

int m=2;
int k=300;
//definicion de las dos derivadas
double dv(float ti, float x1, float v1)
{
    return -(k/m)*x1;
}
double dx(float ti,float x1, float v1){
    return v1;
}

int main(){
    
    //contantes y condiciones iniciales
    
    double G= 6.674*pow(10,-11);
    double M=1.98*pow(10,30);
    double 
        
        x0 = 0:1163UA, y0 = 0:9772UA, vx0 =
􀀀6:35UA/yr y vy0 = 0:606UA/yr
    
    double a=0;
    double b=5;
    double delta=0.01;
    int puntos = (b-a)/delta;
    
    float t[puntos];
    float x[puntos];
    float v[puntos];
    float *pt = t;
    float *px= x;
    float *pv= v;
    t[0]=0;
    x[0]=0.1;
    v[0]=0;
    outfile.open("datos.dat");
    for(int i=1;i<=puntos;i++)
    {
        float k1x=delta*dx(t[i-1],x[i-1],v[i-1]);
        float k1v=delta*dv(t[i-1],x[i-1],v[i-1]);
            
        float k2x=delta*dx(t[i-1]+0.5*delta, x[i-1] + 0.5 * k1x, v[i-1]+ 0.5*k1v);
        float k2v=delta*dv(t[i-1]+0.5*delta, x[i-1] + 0.5 * k1x, v[i-1]+ 0.5*k1x);
            
        float k3x=delta*dx(t[i-1]+0.5*delta, x[i-1]+ 0.5*k2x, v[i-1]+ 0.5*k2v);
        float k3v=delta*dv(t[i-1]+0.5*delta,x[i-1]+ 0.5*k2x, v[i-1]+ 0.5*k2x);
            
        float k4x =delta*dx(t[i-1]+delta, x[i-1]+k3x, v[i-1]+ k3v);
        float k4v =delta*dv(t[i-1]+delta, x[i-1]+k3x, v[i-1]+ k3x);
        float promediox=(1.0/6.0)*(k1x+2.0*k2x+2.0*k3x +k4x);
        float promediov=(1.0/6.0)*(k1v+2.0*k2v+2.0*k3v +k4v);
            
        t[i] = t[i-1] + delta;
        x[i] = x[i-1] + promediox;
        v[i] = v[i-1] + promediov;
        
        cout<<"tiempo "<<i<<" "<<pt[i]<<";"<<"posicion "<<i<<" "<<px[i]<<";"<<"velocidad "<<i<<" "<<pv[i]<<endl;
        outfile<<pt[i]<<";"<<px[i]<<";"<<pv[i]<<endl;
    }
    outfile.close();
    
}