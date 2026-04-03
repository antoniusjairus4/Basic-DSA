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
    Node *head = nullptr;
    Node *tail = nullptr;

    bool zero = true;

    while(zero){

        int val;
        cout << "Enter the value of the linked list: ";
        cin >> val;

        if(val == 0){
            zero = false;
            break;
        }

        Node *new_Node = new Node (val);

        if(head == nullptr){
            head = new_Node;
            tail = new_Node;
        }

        else{
            tail->next = new_Node;
            new_Node->prev = tail;
            tail = new_Node;
        }
    }

    for(Node *print = head; print != nullptr; print = print -> next){
        cout << print -> data << " ";
    }
    return 0;
}