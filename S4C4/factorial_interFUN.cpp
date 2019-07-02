//programa 7: Tome su programa que calcula el factorial de un numero n (y que recibe n interactivamente). Reescribalo usando funciones. La seccion de codigo que calcula el factorial debe ser una funcion independiente que es llamada desde la funcion main. llamelo factorial_interFUN.cpp
#include<iostream>
using namespace std;

double factorial(int x)
{
    double facto=1;
    for(int i=1;i<=x;i++)
    {
        facto*= i;
    }
    
    return facto;
}

int main()
{
    int a;
    cout<<"Ingrese el numero para hacer factorial ";
    cin>>a;
    cout<<factorial(a)<<endl;
        
    return 0; 
}