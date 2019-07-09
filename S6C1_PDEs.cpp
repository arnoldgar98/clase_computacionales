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
    double deltax=0.01;
    double deltat=0.0005;
    double vel=1;
    double r= vel* (deltat/deltax);
    int puntos = (b-a)/deltax;
    //condiciones frontera
    int nt=300;
    double u[puntos];
    double x[puntos];    
    double upast[puntos];
    outfile.open("datos.dat");
    for(int i=0;i<=puntos;i++)
    {
        upast[i]=u[i];
    }
    
    for(int i=0; i<nt;i++)
    {
        x[i]=x[i-1]+deltax;
        for(int j=1;j<puntos;j++)
        {
            u[j]=upast[j]-r*(upast[j]-upast[j-1]);
            
        }
    }
    for(int i=0;i<nt;i++)
    {
        outfile<<x[i]<<";"<<u[i]<<endl;
    }
    outfile.close();    
    return 0;
}