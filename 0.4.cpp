#include<iostream> 
#include<cmath> 
using  namespace  std; 
int isPrime(int x)
{   int i=1,j;
    for(j=2;j<x/2;j++)
    if(x%j==0) i=0;
    return(i);
}
int main() 
{   unsigned  short  a; 
    cin>>a; 
    if(isPrime(a))  cout<<"Y"<<endl; 
    else            cout<<"N"<<endl; 
}

