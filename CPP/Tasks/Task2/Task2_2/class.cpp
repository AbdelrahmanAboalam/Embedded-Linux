#include<iostream>
#include<math.h>
class Calc
{
  private: 
  double x;
  double y;
  char z;
  public:
  void Set_Data(double x , double y )
  {
    this->x=x;
    this->y=y;
   
  }
  double Get_Ans(char o)
  {
    double Ans=1;
    switch (o)
    {
      case '+':
      Ans=this->x+this->y;
      
      break;
      case '-':
      Ans=this->x-this->y;
      
      break;
      case '*':
      Ans=this->x*this->y;
      
      break;
      case '/':
      Ans=this->x/this->y;
      
      break;
      case '^':
      Ans = std::pow(this->x, this->y);
      
      break;
      case 'S':
      Ans=sqrt(this->x);
      return Ans;
      default : 
      std::cout<<"Error in opreator";
      
      

      
    }
    return Ans;
  }

};
int main(void)
{
    Calc M;
    char o;
    M.Set_Data(4,2);
    std::cout<<"Enter ypur operator";
    std::cin>>o;
    std::cout<<M.Get_Ans(o)<<std::endl;
    
    return 0;
}