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
    
    double delta= (b-a)/(numpuntos);
    int arr[numpuntos];
    for(int i=0; i<=numpuntos; i++)
    {       
        deriva[i]= (a+delta*i);
        arr[i]=deriva[i];
        cout<<deriva[i];      
    }
    
    return 0;    
        
}
