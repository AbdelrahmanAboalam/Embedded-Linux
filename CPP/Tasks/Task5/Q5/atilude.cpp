#include<iostream>
#include<vector>

class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        int sum =0;
        int result=0;
        
        for (int i : gain)
        {
            sum=sum+i;
            if(result<sum)
            {
                result=sum;
            }
        }
        if (result>=0)
        {
            return result;
        }
        else 
        return 0;

        
    }
};
int main(void)
{
    Solution attli;
    std::vector<int> xy ={-5,1,5,0,-7};

    std::cout<<attli.largestAltitude(xy);



    return 0;
}