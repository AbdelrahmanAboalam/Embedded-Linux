#include<iostream>


//  https://leetcode.com/problems/add-digits/
class Solution
{

public:
    int addDigits(int num)
    {
        int qut = 10;
        int rem = 0;
        int new_num = 0;

        if (num<10 && num !=0)
        {
            return 1;
        }
        while (qut != 0)
        {
            qut = num / 10; 
            rem = num % 10; 

            new_num = qut + rem; 
            num = new_num;
        }

        return num;
    }
};

int main()
{
    Solution n;

    std::cout << n.addDigits(38) << std::endl;
    std::cout << n.addDigits(111) << std::endl;
    std::cout << n.addDigits(0) << std::endl;
    std::cout << n.addDigits(2) << std::endl;


    return 0;
}