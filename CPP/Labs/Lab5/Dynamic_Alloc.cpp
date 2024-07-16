#include<iostream>
#include<string.h>

namespace DinamicAlloc
{
    int** creat2DArray(int size)
    {
    int **ptr =new int *[size];
    for (int i=0;i<size;i++)
    {
        ptr[i]=new int[5];
    }
    std::cout<<"Allocated"<<std::endl;
    return ptr;
    }

    void delet2DArray(int** ptr,int size)
    {
        for(int i=0;i<size;i++)
        {
            delete[] ptr[i];
        }

        delete[] ptr;
        std::cout<<"Delete Done"<<std::endl;
    }


}

int main (void)
{
    int **ptr = DinamicAlloc::creat2DArray(5);
    DinamicAlloc::delet2DArray(ptr,5);


    return 0;
}