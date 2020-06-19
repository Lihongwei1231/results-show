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
    b1.SetName("C++  ���Գ������(��4��)"); 
    b1.SetAuthor("֣��"); 
    b1.SetIntroduction("����C++����������֪ʶ"); 
    b1.SetDate("201007"); 
    b1.SetPage(529); 
    b2.SetID(2); 
    b2.SetName("��ɢ��ѧ"); 
    b2.SetAuthor("��Т��"); 
    b2.SetIntroduction("���������߼���ν���߼��������ۡ�����ϵͳ��ͼ��"); 
    b2.SetDate("198209"); 
    b2.SetPage(305); 
    b3.SetID(3); 
    b3.SetName("c�������"); 
    b3.SetAuthor("̷��ǿ"); 
    b3.SetIntroduction("����C��������еĻ���֪ʶ��������ʽ���﷨��"); 
    b3.SetDate("201006"); 
    b3.SetPage(355); 
    cout<<"��һ�������"<<endl; 
    s.in(b1); 
    cout<<"�ڶ��������"<<endl; 
    s.in(b2); 
    cout<<"�����������"<<endl; 
    s.in(b3); 
    cout<<"���п���鼮������"<<s.GetCount()<<endl; 
    cout<<"���Ҳ�����ͼ�飺��ɢ��ѧ"<<endl; 
    Book tmpbook=s.findbyName("��ɢ��ѧ"); 
    if(tmpbook.GetID()!=0) 
    {s.out("��ɢ��ѧ"); 
     cout  <<"��ɢ��ѧ  �ѳɹ�����"<<endl;} 
    else  cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl; 
    cout<<"���п���鼮������"<<s.GetCount()<<endl; 
    cout<<"����ͼ��  ID��3"<<endl; 
    tmpbook=s.findbyID(3); 
    if(tmpbook.GetID()!=0) 
        cout<<"�ҵ�IDΪ"<<3<<"���飬������"<<tmpbook.GetName()<<endl; 
    else  cout<<"û���ҵ�IDΪ"<<3<<"����"<<endl; 
    cout  <<"����ͼ��  name����ɢ��ѧ"  <<  endl; 
    tmpbook=s.findbyName("��ɢ��ѧ"); 
    if(tmpbook.GetID()!=0) 
        cout<<"�ҵ�nameΪ��ɢ��ѧ���飬ID��"<<tmpbook.GetID()<<endl; 
    else  cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl; 
    cout<<"������п��ͼ�����Ϣ"<<endl; 
    s.printList(); 
    cout<<"�������н���"<<endl; 
    return  0; 
} 
