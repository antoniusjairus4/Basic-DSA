#include <iostream>

using namespace std;

class Node {
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
    cout << "Enter the number of elements to be in the Linked list: ";
    cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;

    for(int i = 0; i < n; i++){
        cout << "Enter the value of the List: ";
        int val;
        cin >> val;

        Node *new_Node = new Node (val);

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

    Node *max = head;
    for(Node *trav = head ; trav != nullptr; trav = trav -> next){
        if(max -> data > trav -> data){
            max = trav;
        }
    }

    cout << "The max of the Linked list is: " << max;
    
    return 0;
}