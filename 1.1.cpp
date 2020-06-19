#include  <iostream> 
#include  <cmath> 
using  namespace  std; 
int  isPrime(long  num) 
{   int i,j=1;
    if(num>=4)
    for(i=2;i<=num/2;i++)
    if(num%i==0) {j=0;break;}
    return j;
}  
void  factorization(long n,long x[],int &m) 
{   int p;
    for(p=2;p<=n;p++)
    while(isPrime(p)&&n%p==0)
    {x[m++]=p;n/=p;}
	return; 
} 
int  main() 
{   long  n; 
    long  factor[100]; 
    int  numofFactor=0; 
    cin>>n; 
    factorization(n,factor,numofFactor); 
    for(int i=0;i<numofFactor;i++) 
    {cout<<factor[i]<<"  ";} 
    cout<<endl; 
    return  0; 
}
