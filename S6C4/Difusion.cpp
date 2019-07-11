#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    double lado= 1;
    double v= 0.0001;
    double dx = 1;
    double dy= 1;
    double dt=(0.5*(dx*dx))/v;
    double tiem=2500;
    int puntos=100;
    //condiciones iniciales fijas
    double tiempos[puntos];
    double tpasado[puntos][puntos];
    double tinicial[puntos][puntos];
    double tpresente[puntos][puntos];
    double tfuturo[puntos][puntos];
    tpasado[0][0]=50;
    tpresente[0][0]=50;
    tfuturo[0][0]=50;
    tinicial[0][0]=50;
    tinicial[puntos][puntos]=50;
    
    
    ofstream outfile;
    outfile.open("datos.dat"); 
    //construccion del primer paso
    for(int i=1; i<puntos;i++)
    {
        for(int j=1;j<puntos;j++)
        {
            
            if(i>=20&&i<=40&&j>=40&&j<=60)
            {
                tinicial[i][j]=100;
                tpasado[i][j]=tinicial[i][j];
            }
            else{
                tinicial[i][j]=50;    
                tpasado[i][j]=tinicial[i][j];
            }
            
           
        }
    }
    for(int i=0;i<puntos;i++)
    {
        for(int j=0;j<puntos;j++)
        {
            outfile<<tpasado[i][j]<<" ";
        }
        outfile<<"\n";
    }
    outfile.close();
   
    //contruccion del primer futuro
    for(int i=1;i<puntos;i++)
    {
        for(int j=1;j<puntos;j++)
        {
            upresente[i][j]= ((v*dt)/(dx*dx))* (upasado[i+1][j]+upasado[i-1][j]-2*upasado[i][j])+ (v*dt/(dy*dy))* (upasado[i][j+1]+upasado[i][j-1]-2*pasado[i][j])+upasado[i][j];
        }
    }
    
    //construccion en el tiempo
    for(int b=0; b<tiem;b++)
    {
        for(int i=1;i<puntos;i++)
        {
            for(int j=1;j<puntos;j++)
            {
                upresente[i][j]= ((v*dt)/(dx*dx))* (upasado[i+1][j]+upasado[i-1][j]-2*upasado[i][j])+ (v*dt/(dy*dy))* (upasado[i][j+1]+upasado[i][j-1]-2*pasado[i][j])+upasado[i][j];
            }
        }
    }
       
    
        
    return 0;
}
