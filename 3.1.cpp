#include<iostream>
#include<iomanip> 
#include<cmath> 
using namespace std; 
const double PI=3.1415926;
class cylinder
{public:cylinder(double m,double n);
		~cylinder();
		double getvolumn();
        double getarea();
 private:double h,r;		            
};
cylinder::cylinder(double m,double n)
{h=m;r=n;
cout<<"���캯��������"<<endl;}
cylinder::~cylinder() 
{cout<<"��������������"<<endl;}
double cylinder::getvolumn()
{return PI*r*r*h;}
double cylinder::getarea()
{return 2*PI*r*(r+h);}
int main()
{
    double d,h;
    cin>>d>>h;
    cylinder can(h,d/2);
    cout<<fixed<<setprecision(6);
    cout<<"��Ͱ���ݻ���"<<can.getvolumn()<<" "<<endl;
    cout<<"��Ƥ�������"<<can.getarea()<<endl;
}
