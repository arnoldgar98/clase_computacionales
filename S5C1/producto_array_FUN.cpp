#include<iostream>
using namespace std;

int productouno(int a[],int b[]){
    int arr3[5];
    for(int i=0; i<5; i++)
    {
        arr3[i]= a[i]*b[i];
        cout<<arr3[i]<<endl;
    }
    
}

int productopunto(int a[],int b[]){
    int total=0;
    for(int i=0; i<5; i++)
    {
        total += a[i]*b[i];
    }
    cout<<"punto "<<total<<endl;
}
int main(){
    int arr1[5]={1,2,3,4,5};
    int arr2[5]={10,20,30,40,50};
    productouno(arr1,arr2);
    productopunto(arr1,arr2);
    return 0;
        
}
