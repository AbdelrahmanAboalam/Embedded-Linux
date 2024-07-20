#include<iostream>
#include<vector>
#include<string>


class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

       int count[26] = {0}; 

        for (char c : s) {
            count[c - 'a']++;
        }

        for (char c : t) {
            count[c - 'a']--;
            if (count[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};

int main(void)
{
    Solution string;
    std::string s,t;
    std::cout<<"Please enter first string :";
    std::cin>> s;
    std::cout<<"Please enter seconde string:"; 

    std::cin>> t;

    if(string.isAnagram(s,t))
    {
        std::cout<<"t is Anagram of s";
    }
    else
    {
        std::cout<<"t is not Anagram of s";
    }



    return 0;
}