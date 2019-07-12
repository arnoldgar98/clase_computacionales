#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    double lado= 1;
    double v= 0.0001;
    double dx = 0.01;
    double dy= 0.01;
    double dt=(dy*dy)*0.05/v;
    double tiem1=100;
    double tiem2=2500;
    int puntos=100;
    //condiciones iniciales fijas
    double tiempos[puntos];
    double tpasado[puntos][puntos];
    double tinicial[puntos][puntos];
    double tpresente[puntos][puntos];
    double tfuturo[puntos][puntos];
    //condiciones de libre
    double tpasado2[puntos-1][puntos-1];
    double tinicial2[puntos-1][puntos-1];
    double tpresente2[puntos-1][puntos-1];
    
    ofstream outfile;
    outfile.open("datos.dat"); 
    //construccion del primer paso
    for(int j=0; j<puntos;j++)
    {
        for(int i=0;i<puntos;i++)
        {
            
            if(i>=20&&i<=40&&j>=40&&j<=60)
            {
                tinicial[j][i]=100;
                tpasado[j][i]=tinicial[j][i];
                tpresente[j][i]=tpasado[j][i];
                
                tinicial2[j][i]=100;
                tpasado2[j][i]=tinicial[j][i];
                tpresente2[j][i]=tpasado2[j][i];
            }
            else{
                tinicial[j][i]=50;    
                tpasado[j][i]=tinicial[j][i];
                tpresente[j][i]=tpasado[j][i];
                
                tinicial2[j][i]=100;
                tpasado2[j][i]=tinicial[j][i];
                tpresente2[j][i]=tpasado2[j][i];
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
    
    ofstream outfile1;
    ofstream outfile2;
    ofstream outfile3;
    ofstream outfile4;
    //construccion en el tiempo para t=100s
    for(float b=0; b<tiem2; b+=dt)
    {
        
        for(int i=1;i<puntos-1;i++)
        {
            for(int j=1;j<puntos-1;j++)
            {
                tpresente[j][i]= ((v*dt)/(dx*dx))* (tpasado[j+1][i]+tpasado[j-1][i]-2*tpasado[j][i])+ (v*dt/(dy*dy))* (tpasado[j][i+1]+tpasado[j][i-1]-2*tpasado[j][i])+tpasado[j][i];
                tpasado[i][j]=tpresente[i][j];
                
                tpresente2[i][j]= ((v*dt)/(dx*dx))* (tpasado2[i+1][j]+tpasado2[i-1][j]-2*tpasado2[i][j])+ (v*dt/(dy*dy))* (tpasado2[i][j+1]+tpasado2[i][j-1]-2*tpasado2[i][j])+tpasado2[i][j];
                tpasado2[i][j]=tpresente2[i][j];
            }
        }
        if(b<=100)
        {
            outfile3.open("datos3.dat");
            outfile1.open("datos1.dat");
            for(int c=0;c<puntos;c++)
            {
                for(int d=0;d<puntos;d++)
                {
                    outfile1<<tpresente[c][d]<< " ";
                    outfile3<<tpresente2[c][d]<<" ";
                }
                outfile1<<"\n";
                outfile3<<"\n";
            }
            outfile1.close();
            outfile3.close();
        }
        
    }
    
    outfile2.open("datos2.dat");
    outfile4.open("datos4.dat");
    for(int c=0;c<puntos;c++)
    {
        for(int d=0;d<puntos;d++)
        {
            outfile2<<tpresente[d][c]<< " ";
            outfile4<<tpresente2[c][d]<<" ";
        }
        outfile2<<"\n";
        outfile4<<"\n";
    }
    outfile2.close();
    outfile4.close();
    
   
    
    return 0;
}
