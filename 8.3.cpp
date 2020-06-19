#include <iostream> 
using namespace std; 
class Point
{public:Point(int a=0,int b=0){m_x=a;m_y=b;}
        Point& operator++();
        Point operator++(int);
        int getx()const{return m_x;}
        int gety()const{return m_y;}
        friend ostream& operator<<(ostream& x,const Point& c);
private:int m_x,m_y;
};
Point& Point::operator++() 
{m_x++;m_y++;return *this;}
Point Point::operator++(int)
{Point old=*this;m_x++;m_y++;return old;} 
ostream& operator<<(ostream& x,const Point& c)
{x<<"("<<c.getx() <<","<<c.gety()<<")"<<endl;return x;}
int main() 
{   Point a(1,3); 
    cout<<a;    
    cout<<a++; 
    cout<<++a; 
    return  0; 
}
