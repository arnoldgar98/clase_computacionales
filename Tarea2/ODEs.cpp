#include<iostream>
#include<fstream>
using namespace std;


//definicion de las dos derivadas
//En X
double dvenx(float tiempo, float xx, float vx)
{
    double G = pow(6.674*10, -11);
    double M = pow(1.989*10, 30);
    //Unidades astronomicas
    double r12= 1;
    return (-G*M/r12)*0.1163;
}
double dxenx(float tiempo,float xx, float vx){
    return vx;
}
//En Y
double dveny(float tiempo, float yy, float vy)
{
    double G = pow(6.674*10, -11);
    double M = pow(1.989*10, 30);
    //Unidades astronomicas
    double r12= 1;
    return (-G*M/r12)*0.9772;
}
double dxeny(float ti, float yy, float vy)
{
    return vy;
}

//primer método: Euler

float euler()
{
    //creacion de arreglos
    double dif= 0.01;
    float x[puntos], y[puntos], vy[puntos], vx[puntos], tiem[puntos];
    //inicializar con condiciones del enunciado
    x[0]=0.1163;
    y[0]=0.9772;
    vx[0]=-6.35;
    vy[0]=0.606;
    dt=(b-a)/puntos;
    //desde 1, porque ya usamos la condicion inicial
    for(int i=1; i<puntos;i++)
    {
        //avance del tiempo
        tiem[i]=tiem[i-1]+dt;
        //retroalimentacion de las variables al mismo tiempo
        x[i]=x[i-1]+ dif*(dxenx(tiem[i-1],x[i-1],vx[i-1]));
        y[i]=y[i-1]+ dif*(dyenx(tiem[i-1],x[i-1],vy[i-1]));
        vx[i]=vx[i-1]+ dif*(dvenx(tiem[i-1],x[i-1],vx[i-1]));
        vy[i]=vy[i-1]+ dif*(dveny(tiem[i-1],x[i-1],vx[i-1]));
    }           
}

//Segundo Método:Leap frog
float leap_frog()
{
    //creacion de arreglos
    float x[puntos], y[puntos], vy[puntos], vx[puntos], tiem[puntos];
    //inicializacion con condiciones del enunciado
    x[0]=0.1163;
    y[0]=0.9772;
    vx[0]=-6.35;
    vy[0]=0.606;
    dt=(b-a)/puntos;
    //desde 1, porque ya usamos la condicion inicial
    for(int i=1; i<puntos;i++)
    {
        //avance del tiempo
        tiem[i]=tiem[i-1]+dt;
        //retroalimentacion de las variables al mismo tiempo
        x[i]=x[i-1]+ dif*(dxenx(tiem[i-1],x[i-1],vx[i-1]));
        y[i]=y[i-1]+ dif*(dyenx(tiem[i-1],x[i-1],vy[i-1]));
        vx[i]=vx[i-1]+ dif*(dvenx(tiem[i-1],x[i-1],vx[i-1]));
        vy[i]=vy[i-1]+ dif*(dveny(tiem[i-1],x[i-1],vx[i-1]));
    } 
}
//Tercer método: Runge-kutta 4orden
float rungekutta()
{
    double dif= 0.01;
    //creacion de arreglos
    float x[puntos], y[puntos], vy[puntos], vx[puntos], tiem[puntos];
    float k1x,k2x,k3x,k4x,k1vx,k2vx,k3vx,k4vx;
    float k1y,k2y,k3y,k4y,k1vy,k2vy,k3vy,k4vy;
    //inicializacion con condiciones del enunciado
    x[0]=0.1163;
    y[0]=0.9772;
    vx[0]=-6.35;
    vy[0]=0.606;
    dt=(b-a)/puntos;
 
    for(int i=1;i<=puntos;i++)
    {
        k1x=dif*dxenx(tiem[i-1],x[i-1],vx[i-1]);
        k1vx=dif*dvenx(tiem[i-1],x[i-1],vx[i-1]);
            
        k2x=dif*dxenx(tiem[i-1]+0.5*dif, x[i-1]+0.5*k1x,vx[i-1]+0.5*k1vx);
        k2vx=dif*dvenx(tiem[i-1]+0.5*dif, x[i-1]+0.5*k1x,vx[i-1]+0.5*k1vx);
            
        k3x=dif*dxenx(tiem[i-1]+0.5*dif, x[i-1]+0.5*k2x,vx[i-1]+0.5*k2vx);
        k3vx=dif*dvenx(tiem[i-1]+0.5*dif,x[i-1]+0.5*k2x,vx[i-1]+0.5*k2x);
            
        float k4x =delta*dx(t[i-1]+delta, x[i-1]+k3x, v[i-1]+ k3v);
        float k4v =delta*dv(t[i-1]+delta, x[i-1]+k3x, v[i-1]+ k3x);
        float promediox=(1.0/6.0)*(k1x+2.0*k2x+2.0*k3x +k4x);
        float promediov=(1.0/6.0)*(k1v+2.0*k2v+2.0*k3v +k4v);
            
        tiem[i] = tiem[i-1] + delta;
        x[i] = x[i-1] + promediox;
        v[i] = v[i-1] + promediov;
    }
    
}
int main()
{
    return 0;
}
