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
    double delta=0.0005;
    double vel=1;
    
    int puntos = 80;
    double deltax= (b-a)/puntos;
    double r= vel* (delta/deltax);
    //condiciones frontera
    int nt=300;
    double u[puntos];
    double x[puntos];    
    double upast[puntos];
    outfile.open("datos.dat");  
    for(int i=0;i<=puntos;i++)
    {
        x[i]=x[i-1]+deltax;
        if(x[i]>0.75 && x[i]<1.25)
        {
            u[i]=2;
        }
        else{
            u[i]=1;
            
        }
        
    }
    for(int i=0;i<=puntos;i++)
    {
        outfile<<x[i]<<";"<<u[i]<<endl;        
    }
    outfile.close();
    
    
    ofstream outfile1;
    outfile1.open("datos2.dat");               
    for(int i=0; i<nt;i++)
    {
        upast[i]=u[i];
        for(int j=1;j<puntos;j++)
        {
            u[j]=upast[j]-r*(upast[j]-upast[j-1]);
            
        }
    }
    for(int i=0;i<nt;i++)
    {
        outfile1<<x[i]<<";"<<u[i]<<endl;
    }
    outfile1.close();      
    return 0;
}