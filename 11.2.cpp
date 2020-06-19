#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
typedef int elementType;
typedef struct node
{ elementType data;  
  node* next;
}LList,*PList;
class linkedList
{public:
    linkedList();
    virtual ~linkedList();
    void insert(int value);
    bool initiate();
    bool isEmpty();
    bool remove(int pos,int& value);
    void print();
    int Length();
private:
    LList *head;
    int len;
};
linkedList::linkedList() 
{len=0;head=(LList*)malloc(sizeof(LList));head->next=NULL;}
linkedList::~linkedList()
{ if(initiate()) 
  {LList* p=head->next;
   LList* q=p;
   free(head);
   while(p)
   {q=p;p=p->next;free(q);}
}}
void linkedList::insert(int value)
{ if(initiate()) 
  {LList* q=(LList*)malloc(sizeof(LList));
   q->data=value;
   LList* p=head->next;LList* s=head;
   while(p)
   {s=p;p=p->next;}
   q->next=s->next;s->next=q;   
  }
}  
bool linkedList::initiate() 
{ LList *head=new LList;
  if(head==NULL) return false;
  else return true;
}
bool linkedList::isEmpty()
{ if(head->next==NULL) return true;
  else return  false;
 } 
bool linkedList::remove(int pos,int& value) 
{ len=Length(); 
  if(pos<=0)
  {cout<<"pos <= 0, failed"<<endl;return false;}
  else if(pos>len)
  {cout<<"pos > len, failed"<<endl;return false;}	
  else if(len==0)
  {cout<<"len == 0, failed"<<endl;return false;}
   int x=1;
   LList* p=head->next;
   LList *q=head;
   while(x!=pos){x++;q=p;p=p->next;}
   value=p->data;q->next=p->next;free(p);
   return true; 	
}
int linkedList::Length() 
{ int x=0;
  LList* p=head->next;
  while(p)
  {x++;p=p->next;}
  if(x) return x;
  else return -1;
}
void linkedList::print()
{ if(isEmpty())
  {cout<<"Empty"<<endl;return;} 
  LList* tmp=head->next;
  while(tmp)
  {cout<<tmp->data<<" ";
   tmp=tmp->next;
  }
  cout<<endl;
}
int main(int argc, char* argv[])
{   linkedList L1;
    int n;
    int val;
    if(!L1.initiate())
        return 0;
    cin>>n;
    for(int i=0; i<n; i++) 
    {cin>>val;
    L1.insert(val);
    }
    cout << "Origin Length£º" << L1.Length() << endl;
    cout << "data£º" ;
    L1.print();
    cin>>n;
    if (L1.remove(n,val))
    {cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
    cout<< "New Length£º" <<L1.Length()<< endl;
    cout<< "data£º" ;
    L1.print();
    }
    return 0;
}
