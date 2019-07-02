#include<iostream>
using namespace std;

double *derivada(){
    
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
    
    float *deriva;
    deriva= new float[numpuntos];
    deriva[0]=a;
    deriva[numpuntos-1]=b;
    double delta= (b-a)/(numpuntos-1);
    int derivada;
    for(int i=0; i<=numpuntos; i++)
    {
        derivada += delta*i;
    }
    return 0;    
        
}
