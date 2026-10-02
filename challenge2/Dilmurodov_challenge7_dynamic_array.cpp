#include <iostream>
#include <stdexcept>
using namespace std;


class DynamicArray 
{
private:
    int* data;
    int size ;
    int capacity ;

    void resize()
    {
        int new_capacity=capacity*2;

        int*new_data=new int [new_capacity];

        for(int i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }

        delete[]data ;

        data=new_data ;
        capacity = new_capacity ;
    }

public :

    DynamicArray()
    {
        capacity=2;
        size = 0 ;
        data=new int[capacity] ;
    }

    ~DynamicArray()
    {
        delete[] data ;
    }

    void append(int x)
    {

        if (size==capacity)
        {
            resize() ;
        }

        data[size] = x ;
        size++;
    }

    int get(int i) const
    {

        if (i < 0 || i >= size)
        {
            throw out_of_range("Index out of range") ;
        }
        return data[i];
    }

    void set(int i, int x)
    {

        if (i < 0 || i >=size)
        {
            throw out_of_range("Index out of range");
        }
        data[i]=x;
        
    }

    int get_size() const
    {
        return size ;
    }

    int get_capacity() const
    {
        return capacity ;
    }
} ;

int main()
{
    DynamicArray array1 ;

    array1.append(10) ;
    array1.append(20) ;
    array1.append(30);

    cout<< "Test 1: " << endl ;
    cout<< "Element 0: " << array1.get(0)<< endl;
    cout <<"Element 1: " << array1.get(1) << endl;
    cout << "Element 2: "<< array1.get(2) <<endl;

    cout<< "Size: " 
         << array1.get_size() << endl;

    cout << "Capacity: "
         << array1.get_capacity() << endl;
         
    DynamicArray array2 ;

    array2.append(5);
    array2.append(10) ;
    array2.append(15);

    cout << "\nTest 2: " <<endl;

    cout << "Before set: "
         << array2.get(1) << endl;

    array2.set(1, 100) ;

    cout <<"After set: "
         << array2.get(1)<< endl;

    DynamicArray array3 ;

    array3.append(1) ;
    array3.append(2);

    cout<< "\nTest 3:"<< endl ;

    cout << "Capacity before resize: "
         << array3.get_capacity()<<endl;

    array3.append(3) ;

    cout << "Capacity after resize: "
         << array3.get_capacity() << endl ;

    cout <<"Element 0: "
         <<array3.get(0) << endl;

    cout <<"Element 1: "
         <<array3.get(1)<<endl;

    cout << "Element 2: "
         << array3.get(2) << endl;

    return 0;
}