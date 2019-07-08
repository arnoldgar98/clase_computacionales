#include<iostream>
#include<fstream>
using namespace std;
ofstream outfile;
double fun(int a,int b)
{
    return a,b;
}

int main()
{
    double a=0;
    double b=2;
    double delta=0.01;
    int puntos =80;
    
    float t[puntos];
    float x[puntos];
    float v[puntos];
    float u[puntos];
    float *pu= u;
    float *pt =t;
    float *px =x;
    float *pv =v;
    
    t[0]=0;
    outfile.open("datos.dat");
    for(int i=0;i<=puntos;i++)
    {
        t[i]=t[i-1]+delta;
    }
    
    for(int i=0; i<=puntos;i++)
    {
        u[i]=1;
        if(x[i]>0.75 && x[i]<1,25)
        {
            u[i]=2;
            
        }
       
        
    }
    for(int i=0; i<=puntos;i++)
    {
        outfile<<t[i]<<";"<<u[i]<<endl; 
    }
    outfile.close();    
    return 0;
}
