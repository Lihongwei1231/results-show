#include<iostream>
#include<string.h>
using namespace std;
int main()
{   char a[10],b[10];
    int i,j,k,m,n,min=26;
    cin>>a;cin>>b;
	m=strlen(a);
    n=strlen(b);
    for(i=0;i<m;i++)
	if(a[i]>='A'&&a[i]<='Z') a[i]+=32;
	for(i=0;i<n;i++)
	if(b[i]>='A'&&b[i]<='Z') b[i]+=32;
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{if(a[i]>b[j]) k=a[i]-b[j];
	else k=b[j]-a[i];
	if(min>k) min=k;}
	cout<<min<<endl;
}
