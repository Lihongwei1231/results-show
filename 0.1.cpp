#include<iostream> 
using namespace std;
int main()
{
    char a[8];
    int b[8]={0},i,j,k,m=0,n=0;
    for(i=0;i<8;i++)
    cin>>a[i];
    for(i=0;i<8;i++) 
    if(a[i]>'0'&&a[i]<'9') b[i]=a[i]-'0';
    else m=i;
    for(i=1;i<=8;i++)
    {for(j=0,k=0;j<8;j++)
    {if(i!=b[j]) k++;
    else continue;}
    if(k==8) n=i;}
    b[m]=n;
    k=1;
    for(i=0;i<7;i++)
    for(j=i+1;j<8;j++)
    if(b[j]-b[i]==j-i||b[i]-b[j]==j-i) k=0;
    if(k==1) cout<<n<<endl;
    else cout<<"No Answer"<<endl;
    return 0;
}
