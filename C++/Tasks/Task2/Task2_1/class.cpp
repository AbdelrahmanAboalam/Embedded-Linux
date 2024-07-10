#include<iostream>
#include<string>
class Car
{
  private: 
  std::string company;
  std::string model;
  int year;
  public:
  void Set_Data(std::string x , std::string y , int z)
  {
    this->company=x;
    this->model=y;
    this->year=z;
  }
  std::string Get_Company (void)
  {
    return this->company;
  }
     std::string Get_Model (void)
  {
    return this->model;
  }
   int Get_Year(void)
  {
    return this->year;
  }

};
int main(void)
{
    Car M;
    M.Set_Data("Marsedes","M6",2024);
    std::cout<<M.Get_Company()<<std::endl;
    std::cout<<M.Get_Model()<<std::endl;
    std::cout<<M.Get_Year()<<std::endl;
    
    return 0;
}