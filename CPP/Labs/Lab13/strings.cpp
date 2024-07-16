#include<iostream>

int main(void)
{
    std::string text ="The cycle of life is a cycle of cycles";
    while (1)
    {
        int x =text.find("cycle "); 
        
        if(x== std::string::npos)
        break;
        text.replace(x,5,"circle");
    }
    std::cout<<text<<std::endl;

    text.insert((text.find("circle")),"great ");
    std::cout<<text<<std::endl;

    while (1)
    {
        static int y=0;
        static int x=0; 
        x =text.find("circle", x+5); 
        y++;
        if (y != 2)
        continue;
        text.insert(x,"never-ending ");
        break;

    }
    std::cout<<text<<std::endl;

}