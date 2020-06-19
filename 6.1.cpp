#include <iostream> 
using namespace std; 
class  Book 
{public:Book();
        Book(const Book& other);
        void SetID(int x);
        void SetName(string x);
        void SetAuthor(string x);
        void SetIntroduction(string x);
        void SetDate(string x);
        void SetPage(int x);
        int     GetID();
        string  GetName();
        string  GetAuthor();
        string  GetIntroduction();
        string  GetDate();
        int     GetPage();
        virtual ~Book(){};
private:unsigned int m_ID;
        string m_Name;
        string m_Introduction;
		string m_Author;
        string m_Date;
        unsigned int m_Page;
};
Book::Book()
{ m_ID=0;} 
void Book::SetID(int x)
{ m_ID=x;}
void Book::SetName(string x)
{ m_Name=x;}
void Book::SetAuthor(string x)
{ m_Author=x;}
void Book::SetIntroduction(string x) 
{ m_Introduction=x;}
void Book::SetDate(string x)
{ m_Date=x;}
void Book::SetPage(int x)
{ m_Page=x;}
int Book::GetID()
{ return m_ID;}
string Book::GetName() 
{ return m_Name;} 
string Book::GetAuthor()  
{ return m_Author;} 
string Book::GetIntroduction()  
{ return m_Introduction;} 
string Book::GetDate() 
{ return m_Date;}
int Book::GetPage()
{ return m_Page;} 
Book::Book(const Book& other)   
{ m_ID=other.m_ID; 
  m_Name=other.m_Name; 
  m_Introduction=other.m_Introduction; 
  m_Author=other.m_Author; 
  m_Date=other.m_Date; 
  m_Page=other.m_Page; 
}   
class Store 
{public:Store();
        Store(int n);
        virtual ~Store();
        Store(const Store& other);
        void in(Book &b);
		void out(string name);
		Book findbyID(int ID);
		Book findbyName(string name); 
		int  GetCount(); 
	    void printList();
	    void SetCount(int a); 
private:Book *m_pBook;
        unsigned int m_Count;
};  
void Store::SetCount(int a)
{ m_Count=a;}
Store::Store() 
{SetCount(0);m_pBook=NULL;cout<<"Store default constructor called!"<<endl;}
Store::Store(int n)
{SetCount(n);m_pBook=new Book[n];cout<<"Store constructor with (int n) called!"<<endl;} 
Store::~Store()
{ m_Count=0;
  if(m_pBook!=NULL) delete[] m_pBook;
  cout<<"Store destructor called!"<<endl;}
Store::Store(const Store& other)
{ unsigned int i;m_Count=other.m_Count; 
  for(i=0;i<m_Count;i++)
  {m_pBook[i].SetID (other.m_pBook[i].GetID());
   m_pBook[i].SetName(other.m_pBook[i].GetName());
   m_pBook[i].SetAuthor(other.m_pBook[i].GetAuthor());
   m_pBook[i].SetIntroduction(other.m_pBook[i].GetIntroduction());
   m_pBook[i].SetDate(other.m_pBook[i].GetDate());
   m_pBook[i].SetPage(other.m_pBook[i].GetPage());}
  cout<<"Store copy constructor called!"<<endl;
} 
void Store::in(Book &b)
{  unsigned int i;Book *s1=new Book[m_Count+1];
   s1[m_Count].SetID(b.GetID());
   s1[m_Count].SetName(b.GetName());
   s1[m_Count].SetAuthor(b.GetAuthor());
   s1[m_Count].SetIntroduction(b.GetIntroduction());
   s1[m_Count].SetDate(b.GetDate());
   s1[m_Count].SetPage(b.GetPage());
  for(i=0;i<m_Count;i++)
  {s1[i].SetID(m_pBook[i].GetID());
   s1[i].SetName(m_pBook[i].GetName());
   s1[i].SetAuthor(m_pBook[i].GetAuthor());
   s1[i].SetIntroduction(m_pBook[i].GetIntroduction());
   s1[i].SetDate(m_pBook[i].GetDate());
   s1[i].SetPage(m_pBook[i].GetPage());}  
   m_Count++;
  delete[] m_pBook;
  m_pBook=s1;
}
void Store::out(string name)
{ unsigned int i,j=m_Count;Book *s2=new Book[m_Count-1];
  for(i=0;i<m_Count;i++)
  if(name==m_pBook[i].GetName()) j=i; 
  for(i=0;i<j;i++) 
  {s2[i].SetID(m_pBook[i].GetID());
   s2[i].SetName(m_pBook[i].GetName());
   s2[i].SetAuthor(m_pBook[i].GetAuthor());
   s2[i].SetIntroduction(m_pBook[i].GetIntroduction());
   s2[i].SetDate(m_pBook[i].GetDate());
   s2[i].SetPage(m_pBook[i].GetPage());}
  for(i=j;i<m_Count-1;i++) 
  {s2[i].SetID(m_pBook[i+1].GetID());
   s2[i].SetName(m_pBook[i+1].GetName());
   s2[i].SetAuthor(m_pBook[i+1].GetAuthor());
   s2[i].SetIntroduction(m_pBook[i+1].GetIntroduction());
   s2[i].SetDate(m_pBook[i+1].GetDate());
   s2[i].SetPage(m_pBook[i+1].GetPage());}
  m_Count--;
  delete[] m_pBook;
  m_pBook=s2; 
 } 
Book Store::findbyID(int ID)
{ unsigned int i;
  for(i=0;i<m_Count;i++)
  if(ID==m_pBook[i].GetID()) {return m_pBook[i];break;}
  if(i==m_Count) return Book();
}  
Book Store::findbyName(string name) 
{ unsigned int i;
  for(i=0;i<m_Count;i++)
  if(name==m_pBook[i].GetName()) {return m_pBook[i];break;}
  if(i==m_Count) return Book();
}
int Store::GetCount() 
{ return m_Count;}
void Store::printList()
{ unsigned int i;
  cout<<"There are totally "<<m_Count<<" Books:"<<endl;
  for(i=0;i<m_Count;i++)
  {cout<<"ID="<<m_pBook[i].GetID()<<";  " ;
   cout<<"Name:"<<m_pBook[i].GetName()<<";  ";  
   cout<<"Author:"<<m_pBook[i].GetAuthor()<<";  ";   
   cout<<"Date:"<<m_pBook[i].GetDate()<<";"<<endl;}
} 
int  main() 
{   Store s; 
    Book  b1,b2,b3; 
    b1.SetID(1); 
    b1.SetName("C++  语言程序设计(第4版)"); 
    b1.SetAuthor("郑莉"); 
    b1.SetIntroduction("介绍C++及面向对象的知识"); 
    b1.SetDate("201007"); 
    b1.SetPage(529); 
    b2.SetID(2); 
    b2.SetName("离散数学"); 
    b2.SetAuthor("左孝凌"); 
    b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论"); 
    b2.SetDate("198209"); 
    b2.SetPage(305); 
    b3.SetID(3); 
    b3.SetName("c程序设计"); 
    b3.SetAuthor("谭浩强"); 
    b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等"); 
    b3.SetDate("201006"); 
    b3.SetPage(355); 
    cout<<"第一本书入库"<<endl; 
    s.in(b1); 
    cout<<"第二本书入库"<<endl; 
    s.in(b2); 
    cout<<"第三本书入库"<<endl; 
    s.in(b3); 
    cout<<"现有库存书籍数量："<<s.GetCount()<<endl; 
    cout<<"查找并出库图书：离散数学"<<endl; 
    Book tmpbook=s.findbyName("离散数学"); 
    if(tmpbook.GetID()!=0) 
    {s.out("离散数学"); 
     cout  <<"离散数学  已成功出库"<<endl;} 
    else  cout<<"没有找到name为离散数学的书"<<endl; 
    cout<<"现有库存书籍数量："<<s.GetCount()<<endl; 
    cout<<"查找图书  ID：3"<<endl; 
    tmpbook=s.findbyID(3); 
    if(tmpbook.GetID()!=0) 
        cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl; 
    else  cout<<"没有找到ID为"<<3<<"的书"<<endl; 
    cout  <<"查找图书  name：离散数学"  <<  endl; 
    tmpbook=s.findbyName("离散数学"); 
    if(tmpbook.GetID()!=0) 
        cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl; 
    else  cout<<"没有找到name为离散数学的书"<<endl; 
    cout<<"输出所有库存图书的信息"<<endl; 
    s.printList(); 
    cout<<"程序运行结束"<<endl; 
    return  0; 
} 
