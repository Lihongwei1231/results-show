#include<stdio.h>
int main()
{  int x;
   scanf("%d",&x);
   while(x!=1)
   {if(x%2==0)        {x=x/2;printf("%d  ",x);}
    else if(x%2==1)   {x=x*3+1;printf("%d  ",x);}
   }
}
