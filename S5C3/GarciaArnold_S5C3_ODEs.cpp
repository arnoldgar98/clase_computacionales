#include<iostream>
#include<fstream>
using namespace std;
//kg
int m=2;
//N/M
int k=300;
double derivada1(float a,float b)
{
    return -(k/m)*b;
}

double derivadax(){
    return v;
}


double run(double deltat,double iniy,double finy){ 
    
    int puntos=(finy-iniy)/deltat;
    float *pt;
    float t[puntos];
    float x[puntos];
    float *px;
    pt=t;
    px=x;
    t[0]=0;
    x[0]=0.1;
    for(int i=1;i<=puntos;i++)
    {
        float k1=deltat *derivada(xx[i-1],yy[i-1]);
        float k2=deltat*derivada(xx[i-1]+0.5*deltat, yy[i-1] + 0.5 * k1);
        float k3 = deltat * derivada(xx[i-1]+0.5*deltat,yy[i-1]+0.5*k2);
        float k4 = deltat*derivada(xx[i-1]+deltat,yy[i-1]+k3);
        float promedio=(1.0/6.0)*(k1+2.0*k2+2.0*k3 +k4);
        xx[i] = xx[i-1] + deltat;
        yy[i] = yy[i-1] + promedio;
        cout<<xx[i]<<";"<<yy[i]<<endl;
}
    
}

    

int main(){
    double del=0.1;
    double ini= 0;
    double fin=2;
    run(del,ini,fin);
    return 0;
    
}

 
    
