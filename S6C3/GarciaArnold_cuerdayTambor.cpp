#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main()
{
    double pi=3.1416;
    double a=0;
    double b=0.1;
    double l=1.0;
    double c=300;
    double dx= 0.005;
    double dt= (0.5*dx)/c;
    int puntos= l/dx;
    ofstream outfile;
    outfile.open("datos.dat"); 
    //para el primero
    double x[puntos];
    double upas[puntos];
    double uini[puntos];
    double upres[puntos];
    double ufut[puntos];
    //condiciones iniciales primer punto
    x[0]=0;
    uini[0]=0;
    uini[puntos]=0;
    ufut[0]=0;
    ufut[puntos]=0;
    
    //para el segundo punto
    double upas2[puntos];
    double uini2[puntos];
    double upres2[puntos];
    double ufut2[puntos];
    uini2[0]=0;
    ufut2[0]=0;
    
    //para el tercer punto
    double upas3[puntos];
    double uini3[puntos];
    double upres3[puntos];
    double uprespres3[puntos];
    double ufut3[puntos];
    
    //construccion del presente
    for(int i=0;i<puntos/2;i++)
    {
        uini[i]= ((2*0.01)/l)*i*dx;
        upas[i]=uini[i];
        //segundo punto
        upas2[i]=uini[i];
        //tercer punto
        uini3[i]=0;
        upas3[i]=uini3[i];
    }
    for(int i=puntos/2;i<=puntos;i++)
    {
        uini[i]=((-2*0.01)/l)*i*dx+(2*0.01);
        upas[i]=uini[i];
        //segundo punto
        upas2[i]=uini[i];
        //tercer punto
        uini3[i]=0;
        upas3[i]=uini3[i];
    }
    for(int i=0; i<=puntos;i++)
    {
        x[i]=x[i-1]+dx;
        outfile<<x[i]<<";"<<upas[i]<<endl;
    }
    outfile.close();
    
    
    //construccion del primero
    //El primero se ve pero es muy pero muy pequeño, apartir de ese intento contruir los otros 
    
    for(int i=1;i<puntos;i++)
    {
        upres[i]= ((c*c)*(dt*dt)/(2*dx*dx))* (upas[i+1]+upas[i-1]-2*upas[i])+upas[i];
        //segundo punto
        upres2[i]=upres[i];
        upres2[puntos-1]=upres2[puntos-2];
        //Tercer punto, en la ultima condicion, donde ocurre nuevamente la condicion frontera
        uprespres3[i]= ((c*c)*(dt*dt)/(2*dx*dx))* (upas3[i+1]+upas3[i-1]-2*upas3[i])+upas3[i];
        if(i==puntos-1){
            upres3[i]= 0.01*sin(3.0*c*x[i]*pi/(l));
        }
            

        
        
    }
    //para los futuros
    ofstream outfile1;
    outfile1.open("datos1.dat");
    ofstream outfile2;
    outfile2.open("datos2.dat");
    ofstream outfile3;
    outfile3.open("datos3.dat");
    //se define un tiempo de 2*puntos para que realice una oscilacion de amplitud maxima hasta la amplitud minima, con tiempo mas grande empezaria a oscilar de nuevo
    int tiempo=2*puntos;
    ufut[0]=0;
    ufut[puntos]=0;
    int avance=0;
    
    for(int i=0; i<tiempo;i++)
    {
        avance++;
        for(int j=1;j<puntos;j++)
        {
            ufut[j]= ((c*c)*(dt*dt)/(dx*dx))*(upres[j+1]+upres[j-1]-2*upres[j])-upas[j]+(2*upres[j]);
            //segundo punto
            ufut2[j]= ((c*c)*(dt*dt)/(dx*dx))*(upres2[j+1]+upres2[j-1]-2*upres2[j])-upas2[j]+(2*upres2[j]);
            ufut2[puntos-1]=ufut2[puntos-2];
            //Tercer punto, en la ultima condicion, donde ocurre nuevamente la condicion frontera
            ufut3[j]= ((c*c)*(dt*dt)/(dx*dx))*(uprespres3[j+1]+uprespres3[j-1]-2*uprespres3[j])-upas3[j]+(2*uprespres3[j]);
            if(j==puntos-1){
                ufut3[j]=0.01*sin(3.0*c*x[i]*pi/(l));
            }
        }
        for(int b=0;b<=puntos;b++)
        {
            upas[b]=upres[b];
            upres[b]=ufut[b];
            
            if(avance%50==0)
            {
                outfile1<<x[b]<<";"<<upres[b]<<endl;
            }
            
        }
        //segundo punto
        for(int b=0;b<=puntos;b++)
        {
            
            upas2[b]=upres2[b];
            upres2[b]=ufut2[b];
            if(avance%100==0)
            {
                outfile2<<x[b]<<";"<<upres2[b]<<endl;
            }
            
        }
        //tercer punto
        for(int b=0;b<=puntos;b++)
        {
            
            upas3[b]=upres3[b];
            upres3[b]=ufut3[b];
            //la grafica no da aun, no se porque realmente
            if(avance%100==0)
            {
                outfile3<<x[b]<<";"<<upres3[b]<<endl;
            }
            
        }
        
        
        
    }
    outfile1.close();
    outfile2.close();
    outfile3.close();
}