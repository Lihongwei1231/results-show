#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Array
{public:vector<T>a;
        int len;
        Array(int n):len(n){} 
        void input(int n);
        T &operator[](int n){return a[n];}
};
template<typename T>
void Array<T>::input(int n)
{ for(int i=0;i<n&&i<len;i++)
  {T b; 
  cin>>b;
  a.push_back(b);
}}
class Fract
{public:int n,m;
        Fract(int x=0,int y=1);
        void show();
        Fract operator+=(Fract &p);
        friend istream& operator>>(istream& it,Fract& c); 
};
Fract::Fract(int x,int y)
{ int t=1,min;
  if(x*y<0) t=-1; 
  if(x<0) x=-x;if(y<0) y=-y;
  if(x<y)min=x;else min=y;
  for(int i=min;i>1;i--)
  if(x%i==0&&y%i==0)
  {x/=i;y/=i;}
  n=x*t;m=y;
}
void Fract::show()
{ if(n==0) cout<<0<<endl;
  else if(m==1)  cout<<n<<endl;
  else cout<<n<<"/"<<m<<endl;
}
Fract Fract::operator+=(Fract &p) 
{ Fract c(n*p.m+m*p.n,m*p.m);
  return *this=c;
}
istream &operator>>(istream &is, Fract &p)
{ int x, y;
  is>>x>>y;
  Fract temp(x,y);
  p.n=temp.n; p.m=temp.m;
  return is;
}
int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for (unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}


