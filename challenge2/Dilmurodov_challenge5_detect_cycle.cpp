#include <iostream>
using namespace std;

struct Node 
{
    int data ;
    Node*next;

    Node(int value) 
    {
        data  = value ;
        next  = nullptr;
    }
};

bool has_cycle(Node*head) 
{
    Node*slow = head;
    Node*fast =head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow =slow->next ;
        fast =fast->next->next;

        if(slow == fast) 
        {
            return true ;
        }
    }

    return false ;
}

int main()
{
    Node*head1=new Node(1) ;
    head1->next=new Node(2) ;
    head1->next->next=new Node(3) ;

    cout<< "Test Number 1: " ;

    if (has_cycle(head1) ) 
    {
        cout << "Cycle found here " << endl;
    } else 
    {
        cout << "No cycle found" <<endl ;
    }

    Node*head2 =new Node(1) ;
    Node*node2 =new Node(2) ;
    Node* node3 =new Node(3);
    Node*node4= new Node(4) ;

    head2-> next =node2;
    node2-> next =node3;
    node3-> next =node4 ;


    node4->next = node2;
    cout << "Test Number 2: " ;

    if (has_cycle(head2) ) 
    {
        cout << "Cycle found" <<endl ;
    } else 
    {
        cout << "No cycle" <<endl;
    }


    Node* head3 = nullptr;

    cout << "Test Number 3: ";

    if (has_cycle(head3)) {
        cout << "Cycle found here" << endl;
    } else {
        cout << "No cycle found" << endl;
    }

    return 0;
}