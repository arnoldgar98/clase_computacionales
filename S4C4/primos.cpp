#include<iostream>
using namespace std;

int numero1;
int numero2;
int main()
{
    
    cout<<"Ingrese primer entero: ";
    cin>>numero1; 
    cout<<"Ingrese segundo entero: ";
    cin>>numero2;
    for(int i=numero1; i<=numero2;i++)
    {
        bool primo= true;
        for(int j=2; j<i && primo==true;j++)
        {
            if((i%j)==0)
            {
                primo=false;
            }    
        }
        if(primo==true){
            cout<<i<<endl;
        }
               
    }
    return 0;
}
