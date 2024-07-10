#include<iostream>


enum class Error
{
    Bad_Request =400,
    Not_Found =404,
    Server_Error=500,
    Gateway_Timeout=504
};

void func(Error x)
{
    switch (x)
    {
        case Error::Bad_Request:
        std::cout<<"Bad Request"<<std::endl;
        break;
        case Error::Not_Found:
        std::cout<<"Not Found"<<std::endl;
        break;
        case Error::Server_Error:
        std::cout<<"Server Error"<<std::endl;
        break;
        case Error::Gateway_Timeout:
        std::cout<<"Gateway_Timeout"<<std::endl;
        break;
        default:
        std::cout<<"No such error "<<std::endl;
        
    }
}

int main (void)
{
    Error y;
    func (Error::Bad_Request);
    func (Error::Not_Found );
    func (Error::Gateway_Timeout);
    
    return 0;


}