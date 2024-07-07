#include<stdio.h>


int binary_search(int arr[],int low,int high , int x) 
{

while (low<= high)
{
int mid=low+ (high - low )/2;
if(arr[mid] ==x)
return mid;

if (arr[mid]<x)

low = mid+1;

else
high =mid -1;
}
return -1;
}

int main (void)
{
int arr[]={2,3,4,5,8,9,15,20};
int n=sizeof(arr) /sizeof(arr[0]);
int x=9;
int result = binary_search(arr,0,n-1,x);
if (result==-1)
{
    printf("Not found");
}
else 
printf("The index is : %d " ,result);

return 0;
} 

