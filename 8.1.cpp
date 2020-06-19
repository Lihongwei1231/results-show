#include <iostream> 
using namespace std; 
class Complex
{public:Complex(double m=0,double n=0){real=m,image=n;}
        Complex operator+(Complex c1){return Complex(real+c1.real,image+c1.image);}
	    Complex operator-(Complex c2){return Complex(real-c2.real,image-c2.image);}
	    Complex operator+(double x){return Complex(real+x,image);}
	    Complex operator-(double y){return Complex(real-y,image);}
	    void print(){cout<<real<<"+"<<image<<"i"<<endl;}   
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
    return  0; 
} 
