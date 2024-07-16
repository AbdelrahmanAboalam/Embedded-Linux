#include<iostream>









class My_Pair 
{
    std::string first;
    std::string second;
    public:
    My_Pair()
    {
        this->first="NULL";
        this->second="NULL";
    }

    void Set_First (std::string x)
    {
        this->first=x;
    }

    void Set_Second(std::string x)
    {
        this->second=x;
    }

    std::string Get_First(void)
    {
        return this->first;
    }
    std::string Get_Second(void)
    {
        return this->second;
    }
    void Set_Pairs(std::string x, std::string y)
    {
        this->first=x;
        this->second=y;
    }

    void swap (void)
    {
        std::string temp = this->first;
        this->first=this->second;
        this->second=temp;
        std::cout<<"Swaped done"<<std::endl;
        std::cout<<"After swaping the first is = " <<this->first<<std::endl;
        std::cout<<"After swaping the second is = " <<this->second<<std::endl;

    }

};




int main (void)
{
    My_Pair P;
    P.Set_First("Abdelrahman");
    P.Set_Second("Aboalam");
    std::cout<<"The first is ="<<P.Get_First()<<std::endl;
    std::cout<<"The second is ="<<P.Get_Second()<<std::endl;
    P.Set_Pairs("30","45");
    P.swap();


    return 0;
}