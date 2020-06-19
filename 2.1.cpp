#include  <iostream> 
#include  <iomanip> 
using  namespace  std; 
struct  complex 
{   double  r; 
    double  i; 
}; 
complex add(complex x,complex y)
{complex m;
m.r=x.r+y.r;
m.i=x.i+y.i;
return m;
}
complex add(complex x,double y)
{complex m;
m.r=x.r+y;
m.i=x.i;
return m;
}
complex add(double x,complex y)
{complex m;
m.r=x+y.r;
m.i=y.i;
return m;
}
 int  main() 
{   double  num; 
    complex  a,  b,  c; 
    cin>>a.r>>a.i; 
    cin>>b.r>>b.i; 
    cin>>num; 
    c=add(a,b); 
    cout<<c.r<<"+"<<c.i<<"i"<<endl; 
    c=add(a,num); 
    cout<<c.r<<"+"<<c.i<<"i"<<endl; 
    c=add(num,b); 
    cout<<c.r<<"+"<<c.i<<"i"<<endl; 
} 
