#include <stdio.h>
#include <string.h>
void main (void)
{
    char binary [16],binary_dec[16];
    int c;
    int length=0, decimal , indec;
    printf("please enter your binary number");
    scanf("%s",&binary);
    printf("please enter your bdiecimal number");
    scanf("%d",&c);
   
    length=strlen(binary);
    for (int i=0;i<length;i++)
    {
        if (binary[i] == '1')
        {
           decimal=(decimal<<1) | 1; 
        }
        else if (binary[i] == '0')
        {
            decimal=(decimal<<1);
        } 
        else
        {
            printf("Not binary");
        }
    }
    printf("Decimal from binary is = %d \n",decimal);

int k=0;
while (c != 0)
{
        
        indec = c % 2;
        binary_dec[k++] = indec;
        c = c / 2;

}
printf("Binary from Decimal is = ");
for (int j = k-1 ; j>=0;j--)
{
    printf("%d",binary_dec[j]);
}
printf("\nThank you!!!!!\n");

}