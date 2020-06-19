#include<iostream>
#include<cmath>
using namespace std;
class CTime
{private:int nian,yue,ri,shi,fen,miao;
public:CTime(int a,int b,int c,int d=0,int e=0,int f=0);
	   CTime(CTime &p); 
	   ~CTime();
	   int pdrq(int i,int j,int k);
	   int pdsj(int i,int j,int k);
	   int isvalid();
	   int dayDiff(CTime t); 
	   int chazhi(int x,int y,int z);
	   void showTime(); 
}; 
CTime::CTime(int a,int b,int c,int d,int e,int f)
{   if(!pdrq(a,b,c)&&!pdsj(d,e,f))  {cout<<"date and time error!"<<endl;nian=yue=ri=shi=fen=miao=0;}
    else if(!pdrq(a,b,c)) {cout<<"date error!"<<endl;nian=yue=ri=shi=fen=miao=0;}
	else if(!pdsj(d,e,f)) {cout<<"time error!"<<endl;nian=yue=ri=shi=fen=miao=0;}
	else {nian=a;yue=b;ri=c;shi=d;fen=e;miao=f;}cout<<"构造函数被调用"<<endl;}
CTime::CTime(CTime& p) 
{   nian=p.nian;yue=p.yue;ri=p.ri;shi=p.shi;fen=p.fen;miao=p.miao;    
	cout<<"拷贝构造函数被调用"<<endl;}
CTime::~CTime()
{   cout<<"析构函数被调用"<<endl;}
int CTime::pdrq(int i,int j,int k)
{   int m2,s=1;
    if((i%4==0&&i%100!=0)||(i%400==0)) m2=29;
    else m2=28;
    if(i<0||j<=0||j>=13||k<=0||k>31) s=0;
    switch(j)
   {case 1: case 3: case 5: case 7: case 8: case 10: case 12:
     {if(k<1||k>31) s=0;break;}
    case 4: case 6: case 9: case 11:
	 {if(k<1||k>30) s=0;break;}
	case 2:{if(k<1&&k>m2) s=0;break;}}
    return s;}
int CTime::pdsj(int i,int j,int k)
{   if(i>=0&&i<=23&&j>=0&&j<=59&&k>=0&&k<=59) return 1;
    else return 0;}
int CTime::isvalid()
{   if(pdrq(nian,yue,ri)&&pdsj(shi,fen,miao))  return 1;
    else return 0;}
int CTime::chazhi(int x,int y,int z)
{   int cha,n2=28;
    if((x%4==0&&x%100!=0)||(x%400==0)) n2=29;
	x-=1;
	cha=x*365+x/4-x/100+x/400+z;
	switch(y-1)
	{case 11:cha+=30;case 10:cha+=31;case 9:cha+=30;case 8:cha+=31;case 7:cha+=31;case 6:cha+=30;
	case 5:cha+=31;case 4:cha+=30;case 3:cha+=31;case 2:cha+=n2;case 1:cha+=31;case 0:break;}
	return cha;
} 
int CTime::dayDiff(CTime t)
{   int ts,cha1,cha2;
    cha1=chazhi(nian,yue,ri);
    cha2=chazhi(t.nian,t.yue,t.ri);
    if(cha1>=cha2) ts=cha1-cha2;
	else  ts=cha2-cha1;
    return ts;   
}  
void CTime::showTime()
{   cout<<nian<<"/"<<yue<<"/"<<ri<<" "<<shi<<":"<<fen<<":"<<miao<<endl; } 
int  main() 
{   int year,month,day,hour,minute,second; 
    cin>>year>>month>>day>>hour>>minute>>second; 
    CTime t1(year,month,day,hour,minute,second); 
    t1.showTime(); 
    cin>>year>>month>>day>>hour>>minute>>second; 
    CTime t2(year,month,day,hour,minute,second);  
    t2.showTime();
    if(t1.isvalid())          
    {   int  days=0; 
        days=t1.dayDiff(t2); 
        cout<<"这两天之间相隔了"<<days<<"天"<<endl; 
        days=t2.dayDiff(t1); 
        cout<<"这两天之间相隔了"<<days<<"天"<<endl; 
    } 
}
