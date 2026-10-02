#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

class MinStack 
{
private:
    stack<int>data;
    stack<int> minimums;

public:
    void push(int x) 
    {
        data.push(x) ;

        if (minimums.empty() ) 
        {
            minimums.push(x) ;
        } else 
        {
            int current_min= minimums.top() ;

            if (x < current_min) 
            {
                minimums.push(x) ;
            } else 
            {
                minimums.push(current_min) ;
                
            }
        }
    }

    void pop() 
    {
        if (data.empty())
        {
            throw runtime_error("Cannot pop from an empty stack") ;
        }

        data.pop() ;
        minimums.pop() ;
        
    }

    int top()
    {
        if (data.empty() )
        {
            throw runtime_error("empty") ;
        }

        return data.top() ;
        
    }

    int get_min()
    {
        if (minimums.empty())
        {
            throw runtime_error("empty");
        }

        return minimums.top() ;
    }
} ;

int main()
{
    MinStack stack1 ;

    stack1.push(3) ;
    stack1.push(5);
    stack1.push(2) ;

    cout <<"Testing 1:" <<endl ;
    cout << "Min: " <<stack1.get_min()<< endl ;

    stack1.pop() ;

    cout << "Min after pop: "
         <<stack1.get_min()<< endl ;

    MinStack stack2 ;

    stack2.push(10) ;
    stack2.push(7) ;
    stack2.push(4);
    stack2.push(8);

    cout << "\nTesting 2:"<<endl ;
    cout << "Top: " << stack2.top() <<endl;
    cout << "Min: " << stack2.get_min() << endl;

    stack2.pop();

    cout << "Top after pop: "
         << stack2.top()<< endl;

    cout << "Min after pop: "
         << stack2.get_min() <<endl;

    MinStack stack3 ;

    stack3.push(5) ;
    stack3.push(5) ;
    stack3.push(1);
    stack3.push(1);

    cout << "\nTesting 3:" << endl;
    cout << "Min: " << stack3.get_min() <<endl ;

    stack3.pop() ;

    cout << "Min after pop: "
         << stack3.get_min() << endl ;

    stack3.pop();
    cout << "Min after removing both 1s: "
         << stack3.get_min() << endl;

    return 0;
}