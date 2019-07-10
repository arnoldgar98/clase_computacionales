#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    double a=0;
    double b=0.1;
    double l=1.0;
    double c=300;
    double dx= 0.05;
    double dt= (0.5*dx)/c;
    int puntos= l/dx;
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
        upres[i]= ((2*0.01)/l)*i*dx;
    }
    for(int i=puntos/2;i<=puntos;i++)
    {
        upres[i]=((-2*0.01)/l)*i*dx+(2*0.01);        
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
        ufut[i]= ((c*c)*(dt*dt)/(2*dx*dx))* (upres[i+1]+upres[i-1]-2*upres[i])+upres[i];
        
    }
    
    double upas[puntos];
    for(int i=1;i<puntos-1;i++)
    {
        
        upas[i]=upres[i];
        upres[i]=ufut[i];
        outfile1<<upres[i]<<endl;
    }
    outfile1.close();
    
   
    //para los futuros
    ofstream outfile3;
    outfile3.open("datos3.dat");
    int tiempo=1000;
    for(int i=0; i<tiempo;i++)
    {
        for(int j=1;j<=puntos-1;j++)
        {
            ufut[i]= ((c*c)*(dt*dt)/(dx*dx))*(upres[i+1]+upres[i-1]-2*upres[i])-upas[i]+(2*upres[i]);
            
        }
        for(int b=1;b<=puntos-1;b++)
        {
            
            upas[b]=upres[b];
            upres[b]=ufut[b];
            outfile3<<upres[b]<<endl;
        }
        
        
        
    }
    outfile3.close();
    
   
    return 0;
    
}