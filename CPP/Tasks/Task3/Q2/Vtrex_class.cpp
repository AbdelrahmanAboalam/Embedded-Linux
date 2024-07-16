#include <iostream>
#include <cstdlib>
#include <ctime>   

class Vertex
{
    private:
    int x;
    int y;

    public:
     Vertex() : x(0), y(0) {}


    void setRandom() 
    {
        std::srand(std::time(0));

        x = std::rand() % 201 - 100; 
        y = std::rand() % 201 - 100; 

    }

    int getX()  
    {
        return x;
    }

    int getY()  
    {
        return y;
    }

    std::string get_vetrex ()
    {
        std::string s ;
        s="The vetrex is ( " + std::to_string(x) + " , " + std::to_string(y) + " )";
        return s;
    }
};



int main(void)
{
    Vertex x;
    x.setRandom();
    std::cout<<x.get_vetrex()<<std::endl;

    return 0;
}