#include  <iostream> 
#include  <iomanip> 
using  namespace  std;
class Account
{public:void init(const char a[],const char b[],const char c[],int d,double e);
        void printmoney();
        void deposit(double m);
        void withdraw(double n);
private:const char *zhanghao,*xingming,*xingbie; 
        int nianling;double cunkuan=0;
};
void Account::init(const char a[],const char b[],const char c[],int d,double e)
{ double f=100*e;zhanghao=a;xingming=b;xingbie=c;nianling=d;
  if(f-(int)f==0) cunkuan=e;
  else cout<<"������Ľ��Ϸ�"<<endl; }
void Account::printmoney()
{ cout<<xingming<<"�Ĵ��Ϊ"<<fixed<<setprecision(2)<<cunkuan<<endl;}
void Account::deposit(double m)
{ double f=100*m;
  if(f-(int)f==0) cunkuan+=m;
  else cout<<"������Ľ��Ϸ�"<<endl; }
void Account::withdraw(double n)
{ double f=100*n;
  if(f-(int)f!=0) cout<<"������Ľ��Ϸ� "<<endl;
  else if(n>cunkuan) cout<<"���Ĵ�����"<<endl;
  else cunkuan-=n;}
int  main() 
{   Account  tom; 
    tom.init("32020320011001876X",  "Tom  Black",  "��",  19,  2000.89); 
    tom.printmoney();
    tom.deposit(89.471);
    tom.printmoney();
    tom.deposit(10000); 
    tom.printmoney();
    tom.withdraw(10001); 
    tom.printmoney();
    tom.withdraw(10000.123);
    tom.printmoney();
    tom.withdraw(10000.9);
    tom.printmoney();
    Account  jerry; 
    jerry.init("320203200910116569",  "Jerry  Black",  "Ů",  11,  100.956);
    jerry.printmoney();
}
