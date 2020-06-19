#include<iostream>
using namespace std;
int hs(int m,int n,int p) 
{   if(n<2&&p<3) return m;
    int x=n/2+p/3;
    m=m+x;
    n=x+n%2;
    p=x+p%3;
    return hs(m,n,p);
}
int main()
{   int a,b;
	cin>>a;
	b=hs(a,a,a);
	cout<<b<<endl;
}
