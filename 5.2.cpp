#include <iostream> 
#include <string> 
using namespace std;
class CStudent 
{ private:const char *name;
          int age; 
  public:CStudent();
        CStudent(const char p[],int q);
        ~CStudent();
        static int getcount();
        void printname();
		static int count; 
}; 
CStudent::CStudent()
{ count++;name="noname";
  cout<<name<<" is contructing"<<endl;} 
CStudent::CStudent(const char p[],int q)
{ name=p;age=q;count++;
  cout<<name<<" is contructing"<<endl;} 
CStudent::~CStudent() 
{ count--;
  cout<<name<<" is destructing"<<endl;}
int CStudent::getcount() 
{  return count;}
void CStudent::printname() 
{  cout<<"name:"<<name<<endl;}
int CStudent::count=0; 
int main() 
{   cout<<"现在有学生"<<CStudent::getcount()<<endl; 
    {   CStudent stuB[5]; 
        stuB[4].printname(); 
        cout<<"现在有学生"<<CStudent::getcount()<<endl; 
    } 
    cout<<"现在有学生"<<CStudent::getcount()<<endl; 
    {   CStudent stuA[2]={CStudent("Tom",3),CStudent("Jerry",2)}; 
        for(int i=0;i<2;i++) {stuA[i].printname();} 
        cout<<"现在有学生"<<CStudent::getcount()<<endl;
	} 
    cout<<"现在有学生"<<CStudent::getcount()<<endl; 
    return  0; 
}
