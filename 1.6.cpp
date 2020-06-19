#include<stdio.h>
void gujiao(int a)
{if(a==1);
 else if(a%2==0)  {printf("%d  ",a/2);gujiao(a/2);} 
 else if(a%1==0)  {printf("%d  ",a*3+1);gujiao(a*3+1);}
}
int main()
{  int x;
   scanf("%d",&x);
   gujiao(x);
}
