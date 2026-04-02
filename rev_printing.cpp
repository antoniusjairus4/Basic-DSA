#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        Node (int val){
            data = val;
            next = nullptr;
            prev = nullptr;
        }
};

int main()
{
    int n;
    cout << "Enter the number of element to be in the Linked list: ";
    cin >> n;


    Node *head = nullptr;
    Node *tail = nullptr;
    
    for(int i = 0; i < n; i++){

        int val;
        cout << "Enter an value of the element in the list: ";
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

    for(Node *print = tail ; print != nullptr ; print = print -> prev){
        cout << print -> data << " ";
    }

    return 0;
}