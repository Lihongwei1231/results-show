#include<iostream> 
using  namespace  std;
class CPoint
{ public:CPoint(int a=0,int b=0);
         CPoint(CPoint &p);
         int outx(){return x;}
         int outy(){return y;}
  private:int x,y;
};
CPoint::CPoint(int a,int b)
{x=a;y=b;cout<<"CPoint contstructor with default value(0,0) is called."<<endl;}
CPoint::CPoint(CPoint &p)
{x=p.x;y=p.y;cout<<"CPoint copy contstructor is called."<<endl;}
class CRectangle
{ public:CRectangle();
        CRectangle(CPoint m,CPoint n);
        CRectangle(int i,int j,int k,int l);
		CRectangle(CRectangle &p);
        int GetArea();
  private:CPoint s,t;        
};
CRectangle::CRectangle()
{ cout<<"CRectangle default contstructor is called."<<endl;} 
CRectangle::CRectangle(CPoint m,CPoint n):s(m),t(n)
{ cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;} 
CRectangle::CRectangle(int i,int j,int k,int l):s(i,j),t(k,l)
{ cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;}
CRectangle::CRectangle(CRectangle &p):s(p.s),t(p.t)
{ cout<<"CRectangle copy contstructor is called."<<endl;}
int CRectangle::GetArea() 
{int area=0,p,q;
p=t.outx()-s.outx();q=t.outy()-s.outy();
area=p*q;
if(area>=0) return area;
else return(0-area);}
int  main() 
{   int  a=1,b=1,c=6,d=11; 
    cout<<"#  Define  p1  ######"<<endl; 
    CPoint p1; 
    cout<<"#  Define  p2  ######"<<endl; 
    CPoint p2(10,20); 
    cout<<"#  Define  rect1  ######"<<endl; 
    CRectangle rect1; 
    cout<<"#  Define  rect2  ######"<<endl; 
    CRectangle rect2(p1,p2); 
    cout<<"#  Define  rect3  ######"<<endl; 
    CRectangle rect3(a,b,c,d); 
    cout<<"#  Define  rect4  ######"<<endl; 
    CRectangle rect4(rect2); 
    cout<<"#  Calculate  area  ######"<<endl; 
    cout<<"rect1面积为"<<rect1.GetArea()<<endl; 
    cout<<"rect2面积为"<<rect2.GetArea()<<endl; 
    cout<<"rect3面积为"<<rect3.GetArea()<<endl; 
    cout<<"rect4面积为"<<rect4.GetArea()<<endl; 
    system("pause"); 
    return  0; 
} 
