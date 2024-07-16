#include<iostream>
#include<string.h>

namespace MathFunctions
{
    void print(double x)
    {

        std::cout<<x*x<<std::endl;
    }

} // namespace MathFunctions

namespace StringFunctions
{
    void print(char *x)
    {
        for (int i=0 ; x[i] !='\0';i++)
        {
            if (x[i]>= 'a'&& x[i]<= 'z')
            {
                x[i]=x[i]-32;
            }
            else 
            {
                x[i]=x[i]+32;
            }

        }
        for (int i=0 ; x[i]!='\0';i++)
        {
        std::cout<< x[i];
        }
    }

}
namespace ArrayFunctions
{
    void print(int * x , int size)

    {
        int i=0;
        for (i=0;i<size;i++)
        {

        
        std::cout<<x[i]<<std::endl;
        
        }

    }
}

int main (void)
{
    MathFunctions::print(10);
    int x[]={1,2,4,6,0};
    char y[]={"AbdelRahman"};
    StringFunctions::print(y);
    ArrayFunctions::print(x,5);
    return 0;
}