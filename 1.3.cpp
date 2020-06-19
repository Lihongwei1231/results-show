#include<iostream>
#include<iomanip> 
using namespace std;
int main()
{   float a[4],x,y;
    int i;
    for(i=0;i<4;i++)
    cin>>a[i];
	x=a[0]-a[2];
	y=a[1]-a[3];
	cout<<fixed<<setprecision(2)<<x<<" "<<y;
}
