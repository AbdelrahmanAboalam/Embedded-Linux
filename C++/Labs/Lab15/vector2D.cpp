#include<iostream>
#include<vector>

int main (void)
{

    std::vector<std::vector<int>> V = { {1,2,3},
                                        {4,5,6},
                                        {7,8,9}
                                      };



    for (auto &row : V)
    {
         int x=0;
         int y=0;
        for(auto &colm : row)
        {
            
            int temp=0;
            temp = V[x][y];
            V[x][y]=V[y][x];
            V[y][x]=temp;
            y++;
        }
        
        x++;
    }

   int x=0;
    for (auto &row : V)
    {
        
        int y=0;
        for(auto &colm : row)
        {
            
            std::cout<<V[x][y]<<std::endl;
            y++;
        }
            x++;

    }
    return 0;
}