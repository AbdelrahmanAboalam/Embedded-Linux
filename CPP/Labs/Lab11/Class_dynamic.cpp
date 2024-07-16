#include<iostream>

class P
{
    void** ptr;
    int size;
    public:
    P(int x)
    {

        ptr = new[x];
    }
};