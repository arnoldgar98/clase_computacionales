#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    double a=0;
    double b=0.1;
    double l=1.0;
    int puntos= 200;
    double dx= (b-a)/puntos;
    
    double dt=0.005;
    double c=300;
    double x[puntos];
    double u[puntos];
    double upres[puntos];
    double cons= c*(dt/dx);
    
    
    for(int i=0;i<puntos/2;i++)
    {
        upres[i]= ((2*0.01)/l)*i*dt;
    }
    for(int i=puntos/2;i<=puntos;i++)
    {
        upres[i]=((-2*0.01)/l)*i*dt+(2*0.01);        
    }
    for(int i=0; i<=puntos;i++)
    {
        x[i]=x[i-1]+dx;
        cout<<x[i]<<";"<<upres[i]<<endl;
    }
    
    //condiciones iniciales
    upres[0]=0;
    upres[puntos]=0;
    double ufut[puntos];
    ufut[0]=0;
    ufut[puntos]=0;
    
    for(int i=1;i<puntos-1;i++)
    {
        ufut[i]= upres[i]+ ((cons*cons)/2)* (upres[i+1] -2*upres[i]+ upres[i-1]);
    }
    
    double upas[puntos];
    for(int i=1;i<puntos-1;i++)
    {
        upas[i]=upres[i];
        upres[i]=ufut[i];
    }
    
    int tiempo=100;
    for(int i=0; i<tiempo;i++)
    {
        for(int j=1;j<puntos;j++)
        {
            ufut[i]=            
        }
        for(int b=0;b<puntos;b++)
        {
            upas[b]=upres[b];
            upres[b]=ufut[b];
        }
        
    }
    
    
    return 0;
    
}
