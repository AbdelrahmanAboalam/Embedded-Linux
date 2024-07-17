#include<iostream>
#include<string>
class Solution {
public:
    std::string addStrings(std::string num1, std::string num2)
    {
        int num;
        num = std::stoi(num1)+stoi(num2);

        return std::to_string(num);   
    }
};

int main(void)
{
    Solution sum;
    std::string x,y,result;
    std::cout<<"num1 = ";
    std::cin>>x;
    std::cout<<"num2 = ";
    std::cin>>y;

    std::cout<<"The result is = "<<sum.addStrings(x,y);

    return 0;
}