#include<iostream> 
using namespace std; 
const float pi=3.14159; 
class Shape
{public:Shape(int a);
        ~Shape();
        int getid(){return m_ID;}
	    int getArea(){return 0;}
private:int m_ID;	
};
Shape::Shape(int a)
{m_ID=a;cout<<"Shape constructor called:"<<m_ID<<endl;}
Shape::~Shape()  
{cout<<"Shape destructor called:"<<m_ID<<endl;}
class Circle:public Shape
{public:Circle(int a,int b);
        ~Circle();
        int getr(){return r;}
        float getArea(){return pi*r*r;}
private:int r;	
};
Circle::Circle(int a,int b):Shape(b) 
{r=a;cout<<"Circle constructor called:"<<getid()<<endl;}
Circle::~Circle() 
{cout<<"Circle destructor called:"<<getid()<<endl;}
class Rectangle:public Shape
{public:Rectangle(int a,int b,int c);
        ~Rectangle();
        int geth(){return h;}
        int getw(){return w;}
        int getArea(){return h*w;}
private:int h,w;	
};
Rectangle::Rectangle(int a,int b,int c):Shape(c)
{h=a;w=b;cout<<"Rectangle constructor called:"<<getid()<<endl;}
Rectangle::~Rectangle()
{cout<<"Rectangle destructor called:"<<getid()<<endl;}
int main() 
{   Shape s(1);
    Circle c(4,2);
    Rectangle r(4,5,3);
    cout<<"Shape的面积"<<s.getArea()<<endl; 
    cout<<"Circle的面积"<<c.getArea()<<endl; 
    cout<<"Rectangle的面积"<<r.getArea()<<endl; 
}
