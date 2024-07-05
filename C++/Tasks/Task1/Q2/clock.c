#include <stdio.h>

void main (void)
{
long int x;
int y,z,a;

printf("Please Enter Secondes");
scanf("%d",&x);

y=x%60;

x=x-y;

z=x/(60*60);

x=(z*60*60)-x;

a=x/60;

printf("H:M:S -  %d : %d : %d", z , a , y);


}
