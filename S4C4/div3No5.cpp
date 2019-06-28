// programa 4: Haga un programa que imprime todos los numeros entre 0 y 100 que sean divisibles por tres y NO sean divisibles por 5. Llamelo div3No5.cpp
#include<iostream>

using namespace std;

int main()
{
    
    for(int i=0;i<=100;i++)
    {
        
        if((i%3)==0 && (i%5)!=0)
        {
            
            cout<<i<<endl;
        }
        
    }
    return 0;
    
}