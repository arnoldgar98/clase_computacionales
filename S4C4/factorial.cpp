#include<iostream>

using namespace std;
//Haga un programa que calcule el factorial de un numero n. Tome n=7 como ejemplo. llamelo factorial.cpp. Que pasa si toma n=77?

    
int main()
{
    int a=77;
    int b=1;
    for(int i=1;i<=a;i++)
    {
        b*= i;
        
    }
    cout<<b<<endl;
    return b; 
}