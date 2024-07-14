#include<iostream>

// https://leetcode.com/problems/design-parking-system/description/

class ParkingSystem {
    int big_car;
    int med_car;
    int small_car;
public:
    ParkingSystem(int big, int medium, int small) 
    {
        big_car = big;
        med_car = medium;
        small_car = small;
    }
    
    bool addCar(int carType) 
    {
        if(carType == 1)
        {
            if(big_car >= 1)
            {
                big_car--;
                return true;
            }
            else
            {
                return false;
            }
        }

        if(carType == 2)
        {
            if(med_car >= 1)
            {
                med_car--;
                return true;
            }
            else
            {
                return false;
            }
        }
        if(carType == 3)
        {
            if(small_car >= 1)
            {
                small_car--;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};


int main()
{
    ParkingSystem park(1,1,0);

    std::cout << park.addCar(1) << std::endl;

    std::cout << park.addCar(2) << std::endl;

    std::cout << park.addCar(3) << std::endl;

    std::cout << park.addCar(1) << std::endl;

}