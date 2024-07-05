
#include <stdio.h>

void main (void)
{

float x,y,ans;
char z;

printf("please Enter first Number");
scanf("%f",&x);
printf("please Enter second Number");
scanf("%f",&y);
printf("please Enter your operation (+ , - , * , / ) ");
scanf("%c",&z);

if (z == '+')
{
 ans = add(x,y);
 printf("The result = %f /n", ans);
}
else if (z == '-')
{
 ans = sub(x,y);
 printf("The result = %f /n", ans);
}
else if (z == '*')
{
 ans = multibly(x,y);
 printf("The result = %f /n", ans);
}
else if (z == '/')
{
 ans = multibly(x,y);
 printf("The result = %f /n", ans);
}
else 
{
printf("Your Operation is wrong");

}
}
