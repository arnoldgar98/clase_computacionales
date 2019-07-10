#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    double a=0;
    double b=0.1;
    double l=1.0;
    int puntos= 200;
    double dt=0.005;
    double c=300;
    double dx= (b-a)/puntos;
    double cons= (dx/dt*c);
    ofstream outfile;
    outfile.open("datos.dat"); 
    
    double x[puntos];
    double upres[puntos];
    double ufut[puntos];
    //condiciones iniciales
    upres[0]=0;
    upres[puntos]=0;
    ufut[0]=0;
    ufut[puntos]=0;
    
    //construccion del presente
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
        outfile<<x[i]<<";"<<upres[i]<<endl;
    }
    outfile.close();
    
    
    //construccion del primero
    //El primero se ve pero es muy pero muy pequeño, apartir de ese intento contruir los otros 
    ofstream outfile1;
    outfile1.open("datos2.dat"); 
    for(int i=1;i<puntos;i++)
    {
        ufut[i]= ((cons*cons)/2)* (upres[i+1]-2*upres[i]+upres[i-1])+upres[i];
        
    }
    
    double upas[puntos];
    double uprett[puntos];
    for(int i=0;i<=puntos;i++)
    {
        upas[i]=upres[i];
        uprett[i]=ufut[i];
        outfile1<<x[i]<<";"<<uprett[i]<<endl;
    }
    outfile1.close();
    
    
    //para los futuros
    ofstream outfile3;
    outfile3.open("datos3.dat");
    int tiempo=10;
    for(int i=0; i<tiempo;i++)
    {
        for(int j=1;j<puntos;j++)
        {
            ufut[i]=(2.0*(1.0-(cons*cons)))*uprett[i] - upas[i] + (cons*cons)*(uprett[i+1]+uprett[i-1]);
            
        }
        for(int b=0;b<puntos;b++)
        {
            upas[b]=uprett[b];
            uprett[b]=ufut[b];
            outfile3<<x[b]<<";"<<uprett[b]<<endl;
        }
        
    }
    outfile3.close();
    
    
    return 0;
    
}