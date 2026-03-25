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
    cout << "Enter the number of nodes in the linked list";
    cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;

    for(int i = 0; i < n; i++){
        int val;
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

    for(Node *print = head ; print != 0; print = print -> next){
        cout << print -> data;
    }

    return 0;
}