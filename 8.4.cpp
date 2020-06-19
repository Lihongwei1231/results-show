#include<iostream>
using namespace std; 
class base
{public: virtual ~base(){cout<<"base";}};
class derived:public base
{public: virtual ~derived(){cout<<"derived";}};
void f(base *b){delete b;}
int main()
{ base *b=new derived();f(b); return 0;}
