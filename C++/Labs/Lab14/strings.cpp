#include<iostream>



std::string replace2 (std::string &needle ,std::string &haystack ,std::string &replacement )
{
    int x=0;
    
    while(1)
    {
        x=haystack.find(needle,x+needle.size());
        if (x != std::string::npos)
        haystack.replace(x,replacement.size(),replacement);
        else
        break;
        
    }
    return haystack;

}




int main(void)
{
    std::string needle,haystack,replacement;

    std::cout<< "Please Enter your haystack =";
    std::cin>>haystack;

    std::cout<< "Please Enter your needle =";
    std::cin>>needle;

    std::cout<< "Please Enter your replacement=";
    std::cin>>replacement;

     std::cout<< replace2(needle,haystack,replacement);

     return 0;
}