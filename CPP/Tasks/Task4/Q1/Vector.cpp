#include<iostream>
template<typename T>
class Vector2
{
    private:
    T* arr;
    int capacity;
    int currentsize;

    void resize( )
    {
        capacity=capacity*2;
        T* newarr = new T [capacity];
        for (int i =0;i<currentsize;i++)
        {
            newarr[i]=arr[i];
        }
        delete[] arr;
        arr = newarr;
    }

    public:
    Vector2():capacity(1),currentsize(0)
    {
        arr=new T[capacity];
    }
    Vector2(int size): capacity(size),currentsize(0)
    {
        arr= new T[capacity];
    }

    Vector2(int size , T value):capacity(size),currentsize(size)
    {
        arr=new T[capacity];
        for(int i=0;i<size;i++)
        {
            arr[i]=value;
        }
    }

    Vector2(int size , T *value):capacity(size),currentsize(size)
    {
        arr=new T[capacity];
        for(int i=0;i<size;i++)
        {
            arr[i]=value[i];
        }
    }

    Vector2(const Vector2 &old):capacity(old.capacity),currentsize(old.currentsize)
    {
        arr=new T[capacity];
        for(int i=0;i<currentsize;i++)
        {
            arr[i]=old.arr[i];
        }
    }
//---------------------------------------------------------

void pushback(T value)
{
    if (currentsize==capacity)
    {
        resize();
    }
    arr[currentsize++]=value;
}

void popback()
{
    if (currentsize==0)
    {
        std::cout<<"The Vector is Empty"<<std::endl;
    }
    else
    {
        currentsize=currentsize-1;
    }
}

void removeAt(int index)
{
    if (index >= currentsize)
    {
      std::cout<<"The index is over the Vector Size"<<std::endl;
    }
    else if (index<0)
    {
        std::cout<<"The index is not valid"<<std::endl;
    }
    else 
    {
        for(int i = index;i <currentsize-1;i++)
        {
            arr[i] =arr[i+1];
        }
        currentsize=currentsize-1;
    }

}
void insertAt(int index, T value)
{
    if (index >= currentsize)
    {
        std::cout<<"The index is not valid"<<std::endl;
    }
    else
    {
        if (currentsize==capacity)
        {
            resize();
        }
        for (int i=index;i>currentsize;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[index]=value;
        currentsize=currentsize+1;
    }
}

void insertMiddle(T value)
{
    insertAt(currentsize/2 , value);
}

void removeMiddle()
{
    if (currentsize ==0)
    {
        std::cout<<"The Vector is Empty"<<std::endl;
    }
    else
    {
        removeAt(currentsize/2);
    }
}

int size () const
{
    return currentsize;
}

void print()
{
    for (int i=0; i<currentsize;i++)
    {
        std::cout<<arr[i]<< " ";
    }
}

~ Vector2()
{
    delete[] arr;
}
};


int main()
{
    
    Vector2<double> Vec(7,10.2);
    Vector2<double> my_vector(Vec);
    std::cout<<"My size is"<<my_vector.size()<<std::endl;
    my_vector.insertMiddle(5.2);
    my_vector.insertAt(2,7.1);
    my_vector.pushback(6.3);
    std::cout<<"My size is"<<my_vector.size()<<std::endl;
    std::cout<<"My elements is : ";
    my_vector.print();

}