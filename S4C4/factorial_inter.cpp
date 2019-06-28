#include<iostream>

using namespace std;
//programa 5: repita el programa de factorial, pero ahora permita que el usuario ingrese el valor de n. llamelo factorial_inter.cpp

    
int main()
{
    int a;
    int b=1;
    cout<<"Ingrese el numero para hacer factorial";
    cin>>a;
    for(int i=1;i<=a;i++)
    {
        b*= i;
    }
    cout<<b<<endl;
    return 0; 
}