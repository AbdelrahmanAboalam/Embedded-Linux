#include<iostream>

class Time
{
    private:
    int hours;
    int minuts;
    int seconds;

    public:

    Time () 
    {
        hours=0;
        minuts=0;
        seconds=0;
    }
    Time (int hour, int minut , int second)
    {
        this->hours=hour;
        this->minuts=minut;
        this->seconds=second;
    }


    void display(void)
    {
        std::cout<<"The time is : "<< hours <<":"<<minuts<<":"<<seconds<<std::endl;
    }

    Time add_time (const Time a,const Time b)
    {
        Time result ;
        int seconds=0,minuts=0,hours=0;
        seconds=a.seconds+b.seconds;
        minuts=seconds/60;
        result.seconds=seconds%60;
        minuts=minuts + a.minuts+b.minuts;
        hours=minuts/60;
        result.hours=a.hours+a.hours + hours;
        return result;
    }

};

int main()
{
    const Time time1;
    const Time time2(5,15,30);
    const Time time3(5,45,60);
    Time Total;
    Total= Total.add_time(time3 , time2);
    Total.display();

    return 0;
}