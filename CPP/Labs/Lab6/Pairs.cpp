#include<iostream>
#include<utility>
namespace ArrayPair
{
    std::pair<int,int>* creatArray(int size)
    {

        std::pair<int,int> *ptr = new std::pair<int,int>[size];

        return ptr;
    }

    void deleteArray (std::pair<int,int>* pairr)
    {
        delete[] pairr;
    }


    void setPair (std::pair<int,int>* pairr , int index)
    {
        pairr[index].first=10;
        pairr[index].second=15;

    }

    std::pair<int,int>* getPair (std::pair<int,int>* pairr , int index)
    {
        std::pair<int,int>* p ;
        p->first = pairr[index].first;
        p->first = pairr[index].second;
        return p;
    }

    void print (std::pair<int,int>* pairr,int size)
    {
        for (int i=0;i<size;i++)
        {
            std::cout<<"The First pair"<<std::endl;
            std::cout<<pairr[i].first<<std::endl;
            std::cout<<"The seconde pair"<<std::endl;
            std::cout<<pairr[i].second<<std::endl;
        }
    }

}

int main (void)
{

    std::pair<int,int> *p = ArrayPair::creatArray(5);
    ArrayPair::setPair(p , 0);
    ArrayPair::setPair(p , 1);
    ArrayPair::setPair(p , 2);
    ArrayPair::setPair(p , 3);
    ArrayPair::setPair(p , 4);
    ArrayPair::print(p,5);
    return 0;
}