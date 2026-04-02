#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int val){
            data = val;
            next = nullptr;
            prev = nullptr;
        }
};

int main()
{
    int n;
    cout << "Enter the number of elements in the List: ";
    cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;

    for(int i = 0; i < n; i++){
        
        int val;
        cout << "Enter the element of the list: ";
        cin >> val;

        Node *new_Node = new Node(val);
        if(head == nullptr){
            head = new_Node;
            tail = new_Node;
        }

        else{
            tail -> next = new_Node;
            new_Node -> prev = tail;
            tail = new_Node;
        }
    }

    Node *min = head;
    for(Node *trav = head ; trav != nullptr; trav = trav -> next){
        if(trav -> data < min -> data){
            min = trav;
        }
    }

    cout << "The min of the Linked list is: " << min -> data;

    return 0;
}