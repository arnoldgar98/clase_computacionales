#include<iostream>
#include<fstream>
using namespace std;
//Basado en la teoria del repositorio
ofstream outfile;
double derivada(float a,float b)
{
    return -b;
}


int main()
{
    //Para euler
    double deltat=0.1;
    double iniy= 0;
    double finy=2;
    int puntos=(finy-iniy)/deltat;
    float *px;
    float x[puntos];
    float y[puntos];
    float *py;
    px=x;
    py=y;
    x[0]=iniy;
    y[0]=1;
    outfile.open("datos.dat");
    for(int i=1;i<puntos;i++)
    {
        x[i]= x[i-1]+deltat;
        y[i]= y[i-1] +deltat * derivada(x[i-1],y[i-1]);
        outfile<<px[i]<<";"<<py[i]<<endl;
    }
    outfile.close();
    //Para runge-kutta pd: no pude hacerlos en funciones, por eso implemente ambos en el main.
    float *pxx;
    float xx[puntos];
    float yy[puntos];
    float *pyy;
    pxx=xx;
    pyy=yy;
    xx[0]=iniy;
    yy[0]=1;
    outfile.open("datos.dat2");
    for(int i=1;i<=puntos;i++)
    {
        float k1=deltat *derivada(xx[i-1],yy[i-1]);
        float k2=deltat*derivada(xx[i-1]+0.5*deltat, yy[i-1] + 0.5 * k1);
        float k3 = deltat * derivada(xx[i-1]+0.5*deltat,yy[i-1]+0.5*k2);
        float k4 = deltat*derivada(xx[i-1]+deltat,yy[i-1]+k3);
        float promedio=(1.0/6.0)*(k1+2.0*k2+2.0*k3 +k4);
        xx[i] = xx[i-1] + deltat;
        yy[i] = yy[i-1] + promedio;
        outfile<<pxx[i]<<";"<<pyy[i]<<endl;
    }
    outfile.close();
    return 0;
    
    
        
}