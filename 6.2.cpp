#include<iostream> 
#include<vector> 
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
	    int GetCount();
	    void in(Book &b);
	    void out(string name);
	    Book findbyID(int ID);
	    Book findbyName(string name);
	    void printList();
private:vector<Book>m_Books;
};
Store::Store() 
{ cout<<"Store default constructor called!"<<endl;}
Store::Store(int n)
{ m_Books.resize(n);cout<<"Store constructor with (int n) called!"<<endl;}
 Store::~Store() 
{ cout<<"Store destructor called!"<<endl;}
int Store::GetCount() 
{ return m_Books.size();}
Store::Store(const Store& other) 
{ m_Books.assign(other.m_Books.begin(),other.m_Books.end());
  cout<<"Store copy constructor called!"<<endl;
}
void Store::in(Book &b)
{ m_Books.resize(m_Books.size()+1,b);} 
void Store::out(string name)
{ vector<Book>::iterator it=m_Books.begin(); 
  while(it!=m_Books.end()) 
  {if(it->GetName()==name) m_Books.erase(it); 
   else it++;} 
}
Book Store::findbyID(int ID)
{ vector<Book>::iterator it=m_Books.begin(); 
  for(;it!=m_Books.end();it++) 
  if(it->GetID()==ID)
  {return *it;break;}
  if(it==m_Books.end()) return Book();	
 } 
Book Store::findbyName(string name)
{ vector<Book>::iterator it=m_Books.begin(); 
  for(;it!=m_Books.end();it++) 
  if(it->GetName()==name)
  {return *it;break;}
  if(it==m_Books.end()) return Book();	
}
void Store::printList()
{ cout<<"There are totally "<<m_Books.size()<<" Books:"<<endl; 
  vector<Book>::iterator it=m_Books.begin(); 
  while(it!=m_Books.end()) 
  {cout<<"ID="<<it->GetID()<<";  " ;
   cout<<"Name:"<<it->GetName()<<";  ";  
   cout<<"Author:"<<it->GetAuthor()<<";  ";   
   cout<<"Date:"<<it->GetDate()<<";"<<endl;
   it++;}	
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
