#include <iostream> 
using namespace std; 
class Complex
{public:Complex(double m=0,double n=0){real=m,image=n;}
        friend Complex operator+(Complex c1,Complex c2){return Complex(c1.real+c2.real,c1.image+c2.image);}
	    friend Complex operator-(Complex c1,Complex c2){return Complex(c1.real-c2.real,c1.image-c2.image);}
	    friend Complex operator+(double x,Complex d){return Complex(x+d.real,d.image);}
	    friend Complex operator-(double x,Complex d){return Complex(x-d.real,-d.image);}
	    friend Complex operator+(Complex d,double x){return Complex(d.real+x,d.image);}
	    friend Complex operator-(Complex d,double x){return Complex(d.real-x,d.image);}
	    void print(){cout<<"("<<real<<")"<<"+"<<"("<<image<<"i)"<<endl;}   
private:double real,image;
};
int main() 
{   Complex a(3,4),b(1,-1),c; 
    c=a+b; 
    cout<<"a+b="; 
    c.print(); 
    cout<<endl; 
    c=a-b; 
    cout<<"a-b="; 
    c.print(); 
    cout<<endl; 
    c=a+100; 
    cout<<"a+100="; 
    c.print(); 
    cout<<endl; 
    c=a-2.5; 
    cout<<"a-2.5="; 
    c.print(); 
    cout<<endl; 
    c=100+a; 
    cout<<"100+a="; 
    c.print(); 
    cout<<endl; 
    c=2.5-a; 
    cout<<"2.5-a="; 
    c.print(); 
    cout<<endl; 
    return  0; 
} 
