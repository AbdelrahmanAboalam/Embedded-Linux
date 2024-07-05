#include<stdio.h>
#include<string.h>
typedef struct 
{
     struct
    {
        char First_Name[20];
        char Middel_Name[20];
        char Last_Name[20];
    }Name;

     struct
    {
        int Mounth,Day, Year;

    }Birth;

     struct
    {
        char Street[40];
        char City[40];
        char Country[40];
    }Address;

     struct
    {
        char Telephone_Number[15];
        char Mobile_Number[15];
        char Email[30];
    }Contat;
    char job[35];
     struct
    {
        int Basic , Additional ,Reduction , Taxes; 
    }Salary;
    
}Emblyee;

void main (void)
{
    Emblyee Abdo = {{"Abdelrahman" , "Ahmed" , "Aboalam"},{11,9,1998},{ "Elsopky_Street","Menof","Egypt" }, 
    {"01097926631","01097926631","abdoabo3lm@gmail.com" },"Android Automotive Developer",{20000,5000,2500,1500}};

    printf("The name of Employee is : %s %s %s \n ", Abdo.Name.First_Name,Abdo.Name.Middel_Name,Abdo.Name.Last_Name);
    printf("The Birthdate of Employee is : %d:%d:%d \n ", Abdo.Birth.Day,Abdo.Birth.Mounth,Abdo.Birth.Year);
    printf("The Address of Employee is : %s - %s - %s \n", Abdo.Address.Street,Abdo.Address.City,Abdo.Address.Country);
    printf("The Phone of Employee is : %s \n ", Abdo.Contat.Telephone_Number);
    printf("The Mobile of Employee is : %s \n ", Abdo.Contat.Mobile_Number);
    printf("The Phone of Employee is : %s \n ", Abdo.Contat.Email);
    printf("The Job of Employee is : %s \n ", Abdo.job);
    printf("The Total Salary of Employee is : %d \n ", (Abdo.Salary.Basic+Abdo.Salary.Additional-Abdo.Salary.Reduction-Abdo.Salary.Taxes));

    printf("-----------------------------------------------------");
 
    
    
}