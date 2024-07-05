#include <stdio.h>

void main (void)
{
 int x=0,result=0;
 
 printf("please enter number");
 
 scanf("%d",&x);
while(x !=0)
{
result=result+x;
 printf("please enter nem number");
 
 scanf("%d",&x);
}
printf("The result is : %d",result);
}
