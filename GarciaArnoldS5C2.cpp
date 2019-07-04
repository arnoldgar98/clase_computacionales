#include<iostream>
using namespace std;


double derivada(double a,double b)
{
    return -b;
}


int main()
{
    double deltat=0.1;
    double iniy= 0;
    double finy=2;
    int puntos=(finy-iniy)/deltat;
    double *px;
    double x[puntos];
    double y[puntos];
    double *py;
    *px=x;
    *py=y;
    x[0]=iniy;
    y[0]=1;
    for(int i=0;i<puntos;i++)
    {
        x[i]= x[i-1]+deltat;
        y[i]= y[i-1] +deltat * derivada(x[i-1],y[i-1]);
        cout<<px;
    }
    
    
    
        
}