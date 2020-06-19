#include <iostream>
using namespace std;
class watch
{public:
    watch()
   {m_hour = 0;
    m_min = 0;
    m_sec = 0;
    cout << "watch default constructor called" << endl;        
   }
    watch(int h, int m, int s)
   {m_hour = h;
    m_min = m;
    m_sec = s;
    cout << "watch constructor called" << endl;
   }
protected:
    int m_hour;
    int m_min;  
    int m_sec; 
};
class watchDerived : public watch
{public:
    watchDerived();
    watchDerived(int h,int m,int s);
    void setzero(){m_hour=m_min=m_sec=0;}
    watchDerived& operator++();
    watchDerived operator++(int);
    friend ostream &operator<<(ostream &, const watchDerived &);
    friend istream &operator>>(istream &,  watchDerived &);
};
watchDerived::watchDerived():watch()
{   cout<<"watchDerived default constructor called"<<endl;}
watchDerived::watchDerived(int h,int m,int s):watch(h,m,s)
{  	cout<<"watchDerived constructor called"<<endl;}
watchDerived& watchDerived::operator++() 
{   m_sec++;
    if(m_sec==60)
    {m_min++;m_sec=0;
    if(m_min==60)
    {m_hour++;m_min=0;
    if(m_hour==12)
    {m_hour=0;}}}
    return *this;}
watchDerived watchDerived::operator++(int)
{   watchDerived old=*this;
    m_sec++;
    if(m_sec==60)
    {m_min++;m_sec=0;
        if(m_min==60)
        {m_hour++;m_min=0;
            if(m_hour==12)
            {m_hour=0;}}}
    return old;} 
ostream &operator<<(ostream &out, const watchDerived &s)
{   out<<s.m_hour<<":"<<s.m_min<<":"<<s.m_sec;
    return cout;}
istream &operator>>(istream & in,  watchDerived &s)
{   in>>s.m_hour>>s.m_min>>s.m_sec;
    return in;}

int main()
{   watchDerived s1, s2(11, 59, 59);
    s1=s2++;
    cout<<"s1: "<<s1<<endl;
    cout<<"s2: "<<s2<<endl;
    s1.setzero();
    s2.setzero();
    s1=++s2;
    cout<<"s1: "<<s1<<endl;
    cout<<"s2: "<<s2<<endl;
    cin>>s1;
    cout<<"s1: "<<++s1<<endl;
    return 0;
}
