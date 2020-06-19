#include<iostream>
#include<fstream>
using namespace std;
int main()
{   double a[100],b;int i=0,j,k=0;
    ifstream pa("a.txt",ios::in);
    ofstream pb("b.txt",ios::out);
    if(pa)
    { while(!pa.fail())
      {pa>>a[i];i++;}
      k=i-1;
	}
	pa.close(); 
	for(i=0;i<k-1;i++)
	for(j=i+1;j<k;j++)
	if(a[i]>a[j]){b=a[i];a[i]=a[j];a[j]=b;}
	for(i=0;i<k;i++)
	{pb<<a[i]<<" ";}
    pb.close(); 
} 
