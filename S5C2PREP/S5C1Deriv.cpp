#include<iostream>
#include<math.h>
using namespace std;


float *derivada(int punt, float arre[], double delt){
    float *derivada;
    derivada= new float[punt];
    for(int i=0; i<punt;i++)
    {  
        derivada[i]=(arre[i+1]-arre[i-1])/(2*delt);
        cout<<derivada[i] << " ";
    }
    return derivada;
    
}

int main()
{
    int a;
    int b;
    int numpuntos;
    cout<<"Ingrese el primer numero ";
    cin>>a;
    cout<<"Ingrese el segundo numero ";
    cin>>b;
    cout<<"Ingrese el numero de puntos ";
    cin>>numpuntos;
    
    float *x;
    x= new float[numpuntos];
    
    double delta= (b-a)/(numpuntos);
    float *arr;
    arr= new float[numpuntos];
    for(int i=0; i<=numpuntos; i++)
    {       
        x[i]= (a+delta*i);
        arr[i]=x[i];
        cout<<arr[i]<<endl;      
    }
    
    float *coseno;
    coseno= new float[numpuntos];
    for(int j=0;j<=numpuntos;j++){
        coseno[j]=cos(arr[j]);
        cout<<coseno[j]<<" ";
    }
    derivada(numpuntos,coseno,delta);
    
    return 0;    
        
}
