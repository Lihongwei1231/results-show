#include  <iostream> 
using  namespace  std;
class Car; 
class Boat
{ public:Boat(int a);  
  friend int totalweight(Boat& b,Car& c);   
  private:int weight;};
Boat::Boat(int a)
{weight=a;}
class Car
{ public:Car(int a);
  friend int totalweight(Boat& b,Car& c);
  private:int weight;};
Car::Car(int a)
{weight=a;}  
int totalweight(Boat& b,Car& c) 
{ return b.weight+c.weight;} 
int main() 
{   Boat b(100); 
    Car  c(200); 
    cout<<totalweight(b,c)<<endl; 
    return  0; 
} 
