#include<iostream>
#include<fstream>
using namespace std;
struct student
{ short  stu_id,score;
};
int main()
{   int n,i;
    cin>>n;
    student a[n],b[n];
    for(i=0;i<n;i++)
    cin>>a[i].stu_id>>a[i].score;
	ofstream pa("out.txt",ios::binary);
	pa.write((char*)a,sizeof a); 
	pa.close(); 
	ifstream pb("out.txt",ios::binary);
	for(i=0;i<n;i++)
	pb.read((char*)&b[i],sizeof(b[i])); 
	pb.close();
	ofstream pc("out.txt",ios::out|ios::ate); 
	pc.write((char*)b,sizeof b); 
	pc.close(); 
}
