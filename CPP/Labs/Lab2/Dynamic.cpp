#include <iostream>

using namespace std;
struct vec
{
    int size;
    int Capacity;
    int * PtrToData;
};

vec * Vector_Create(int Size) /
{
    vec * My_Vec = (vec *)malloc(sizeof(vec)); 
    My_Vec->PtrToData = (int *)malloc(Size * sizeof(int)); 
    My_Vec->size = Size;
    My_Vec->Capacity = Size; 
    return My_Vec;
}

void Vector_DeleteFromMemory(vec * My_Vec)
{
    if (NULL != My_Vec)
    {
        free(My_Vec->PtrToData);
        free(My_Vec);
    }
}

void Vector_PrintAllElements(vec * My_Vec)
{
    if (NULL != My_Vec)
    {
        cout << "Your Vector Data Collection: \n";
        for (int i = 0; i < My_Vec->size; i++)
        {
            printf("%d ", My_Vec->PtrToData[i]);
        }
       cout << endl;
    }
}

void Vector_PrintOneElement(vec * My_Vec, int Index)
{
    if (Index >= My_Vec->size || Index < 0)
    {
        cout << "Out Of Boundary!!" << endl;
    }
    else
    {
        printf("The %d Element is: %d\n", Index, My_Vec->PtrToData[Index]);
    }
}

void Vector_InsertOneElement(vec * My_Vec, int Index, int value)
{
    if (My_Vec->Capacity > My_Vec->size && Index == My_Vec->size) 
    {
        My_Vec->PtrToData[Index] = value;
        My_Vec->size++;
    }
    else
    {
        if (Index < 0 || Index > My_Vec->size)
        {
            cout << "Out of Boundaries" << endl;
        }
        else
        {
            if (My_Vec->size == My_Vec->Capacity) 
            {
                My_Vec->Capacity *= 2;
                My_Vec->PtrToData = (int *)realloc(My_Vec->PtrToData, My_Vec->Capacity * sizeof(int));
            }

           
            for (int i = My_Vec->size; i > Index; i--)
            {
                My_Vec->PtrToData[i] = My_Vec->PtrToData[i - 1];
            }

            
            My_Vec->PtrToData[Index] = value;
            My_Vec->size++;
        }
    }
}

void Vector_DeleteOneElement(vec * My_Vec, int Index)
{
    if (My_Vec->size == 0)
    {
        cout << "No Elements to delete" << endl;
    }
    else
    {
        if (Index < 0 || Index >= My_Vec->size)
        {
            cout << "Out of Boundaries" << endl;
        }
        else
        {
           
            for (int i = Index; i < My_Vec->size - 1; i++)
            {
                My_Vec->PtrToData[i] = My_Vec->PtrToData[i + 1];
            }

            My_Vec->size--;
        }
    }
}

int main()
{
    int initialSize = 5;
    vec *myVector = Vector_Create(initialSize);

    
    for (int i = 0; i < initialSize; i++)
    {
        myVector->PtrToData[i] = i + 1;
    }

    
    Vector_PrintAllElements(myVector);

    
    cout << "\nInserting 99 at index 2" <<endl;
    Vector_InsertOneElement(myVector, 2, 99);
    Vector_PrintAllElements(myVector);

    
    cout << "\nPrinting element at index 2" << endl;
    Vector_PrintOneElement(myVector, 2);

    
    cout << "\nDeleting element at index 2" << endl;
    Vector_DeleteOneElement(myVector, 2);
    Vector_PrintAllElements(myVector);

    
    Vector_DeleteFromMemory(myVector);

    return 0;
}
