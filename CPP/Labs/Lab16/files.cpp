#include<iostream>
#include<fstream>
#include <iomanip>


int main(void)
{
    std::ifstream input("file.txt");

    if (!input)
    {
        std::cerr<<"Error in file";
    }
    int number;
    int sum = 0;
    int count = 0;
    int max=0,min=0;

    while(input >> number)
    {
        sum +=number;
        if (min>max)
        {
            int temp =max;
            max=min;
            min=temp;
        }
        else if (number > max)
        {
            max=number;
        }
        else if (number<min)
        {
            min=number;
        }
        count++;
        
    }
    input.close();
    double avr = static_cast<double> (sum)/count;

    std::ofstream output("out.txt");



    
   
 output << std::setw(50) << std::setfill('-') << "" << std::endl;
    output << "|" << std::setw(6) << std::setfill(' ') << "Sum" << std::setw(6) << std::setfill(' ') << "|"
           << std::setw(6) << std::setfill(' ') << "Avg" << std::setw(6) << std::setfill(' ') << "|"
           << std::setw(6) << std::setfill(' ') << "Min" << std::setw(6) << std::setfill(' ') << "|"
           << std::setw(6) << std::setfill(' ') << "Max" << std::setw(6) << std::setfill(' ') << "|" << std::endl;
    output << std::setw(50) << std::setfill('-') << "" << std::endl;
    output << "|" << std::setw(6) << std::setfill(' ') << sum << std::setw(6) << std::setfill(' ') << "|"
           << std::setw(6) << std::setfill(' ') << std::setprecision(2) << std::fixed << avr << std::setw(6) << std::setfill(' ') << "|"
           << std::setw(6) << std::setfill(' ') << min << std::setw(6) << std::setfill(' ') << "|"
           << std::setw(6) << std::setfill(' ') << max << std::setw(6) << std::setfill(' ') << "|" << std::endl;
    output << std::setw(50) << std::setfill('-') << "" << std::endl;



    return 0;
}















