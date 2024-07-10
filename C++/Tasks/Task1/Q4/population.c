#include<stdio.h>

void main (void)
{
    long int pop=162100;
    int x = 2023;
    while (pop<1000000)
    {
        pop= pop + (pop * (6.5/100));
        printf("The population in %d is %ld \n", ++x , pop );
    }
}