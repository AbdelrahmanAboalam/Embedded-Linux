#include <iostream>

template<typename T , typename T2>
class Key
{
    T keyy;
    T2 value;
    
    public:
    Key (T x , T2 y)
    {
        this->keyy=x;
        this->value=y;
    }

    void Set_Key (T x , T2 y)
    {
        this->keyy=x;
        this->value=y;

    }

    T2 Get_Value ()
    {
        return this->value;
    }
    T Get_Key()
    {
        return this->keyy;
    }
};

int main (void)
{
    Key <std::string,int> P ("Key",0);
    P.Set_Key("AHMED",123);
    std::cout<<"The Value of Key ("<<P.Get_Key()<<") is ="<<P.Get_Value()<<"\n";





    return 0;
}