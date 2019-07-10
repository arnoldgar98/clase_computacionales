#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    double a=0;
    double b=0.1;
    double l=1.0;
    double c=300;
    double dx= 0.005;
    double dt= (0.5*dx)/c;
    int puntos= l/dx;
    ofstream outfile;
    outfile.open("datos.dat"); 
    
    double x[puntos];
    double upres[puntos];
    double ufut[puntos];
    //condiciones iniciales
    x[0]=0;
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
    
    for(int i=1;i<puntos;i++)
    {
        ufut[i]= ((c*c)*(dt*dt)/(2*dx*dx))* (upres[i+1]+upres[i-1]-2*upres[i])+upres[i];
        
    }
    //para los futuros
    ofstream outfile3;
    outfile3.open("datos3.dat");
    int tiempo=500;
    double ufuturo[puntos];
    ufuturo[0]=0;
    ufuturo[puntos]=0;
    int cont=0;
    
    for(int i=0; i<tiempo;i++)
    {
        cont++;
        for(int j=1;j<puntos;j++)
        {
            ufuturo[j]= ((c*c)*(dt*dt)/(dx*dx))*(ufut[j+1]+ufut[j-1]-2*ufut[j])-upres[j]+(2*ufut[j]);
            
        }
        for(int b=0;b<=puntos;b++)
        {
            upres[b]=ufut[b];
            ufut[b]=ufuturo[b];
            if(cont%20==0)
            {
                outfile3<<x[b]<<";"<<ufut[b]<<endl;
            }
            
        }
        
        
        
    }
    outfile3.close();
    
   //Para libres
    //condiciones iniciales
    x[0]=0;
    upres[0]=0;
    ufut[0]=0;
    //construccion del presente
    for(int i=0;i<puntos/2;i++)
    {
        upres[i]= ((2*0.01)/l)*i*dx;
    }
    for(int i=puntos/2 ;i<=puntos;i++)
    {
        upres[i]=((-2*0.01)/l)*i*dx+(2*0.01);        
    }
    for(int i=0; i<=puntos;i++)
    {
        x[i]=x[i-1]+dx;
        
    }
    
    //construccion del primero
    //El primero se ve pero es muy pero muy pequeño, apartir de ese intento contruir los otros 
    
    for(int i=1;i<=puntos;i++)
    {
        ufut[i]= ((c*c)*(dt*dt)/(2*dx*dx))* (upres[i+1]+upres[i-1]-2*upres[i])+upres[i];
        
    }
    //para los futuros
    int tiempo2=500;
    ufuturo[0]=0;
    int cont2=0;
    ofstream outfile4;
    outfile4.open("datos4.dat");
    
    
    for(int i=0; i<tiempo2;i++)
    {
        cont2++;
        for(int j=1;j<=puntos;j++)
        {
            ufuturo[j]= ((c*c)*(dt*dt)/(dx*dx))*(ufut[j+1]+ufut[j-1]-2*ufut[j])-upres[j]+(2*ufut[j]);
            
        }
        for(int b=0;b<=puntos;b++)
        {
            upres[b]=ufut[b];
            ufut[b]=ufuturo[b];
            if(cont2%20==0)
            {
                outfile4<<x[b]<<";"<<ufut[b]<<endl;
            }
            
        }
    }
    outfile4.close();
    return 0;
    
}