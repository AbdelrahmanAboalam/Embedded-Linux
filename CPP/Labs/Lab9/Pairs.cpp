#include<iostream>







template<typename T>

class My_Pair 
{
    T first;
    T second;
    public:
    My_Pair()
    {
        this->first=0;
        this->second=0;
    }

    void Set_First (T x)
    {
        this->first=x;
    }

    void Set_Second(T x)
    {
        this->second=x;
    }

    T Get_First(void)
    {
        return this->first;
    }
    T Get_Second(void)
    {
        return this->second;
    }
    void Set_Pairs(T x, T y)
    {
        this->first=x;
        this->second=y;
    }

    void swap (void)
    {
        T temp = this->first;
        this->first=this->second;
        this->second=temp;
        std::cout<<"Swaped done"<<std::endl;
        std::cout<<"After swaping the first is = " <<this->first<<std::endl;
        std::cout<<"After swaping the second is = " <<this->second<<std::endl;

    }

};




int main (void)
{
    My_Pair<int> P;
    P.Set_First(15);
    P.Set_Second(20);
    std::cout<<"The first is ="<<P.Get_First()<<std::endl;
    std::cout<<"The second is ="<<P.Get_Second()<<std::endl;
    P.Set_Pairs(30,45);
    P.swap();


    return 0;
}