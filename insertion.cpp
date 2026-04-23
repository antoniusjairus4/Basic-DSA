#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements to be in the linked list: ";
    cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i = 0; i < n; i++) {

        int val;
        cout << "Enter a number of the node: ";
        cin >> val;

        Node *new_Node = new Node(val);
        
        if (head == nullptr) {
            head = new_Node;
            tail = new_Node;
        }
        else {
            tail -> next = new_Node;
            new_Node -> prev = tail;
            tail = new_Node;
        }
    }

    int pos;
    cout << "Enter position to insert: ";
    cin >> pos;

    int val;
    cout << "Enter value to insert: ";
    cin >> val;

    Node* new_Node = new Node(val);

    if (pos == 1) {
        new_Node -> next = head;
        if (head != nullptr){
            head -> prev = new_Node;
        }
        head = new_Node;
    }
    else {
        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp -> next;
        }

        if (temp == nullptr) {
            cout << "Position out of range\n";
        }
        else {
            new_Node -> next = temp -> next;
            new_Node -> prev = temp;

            if (temp -> next != nullptr)
                temp -> next -> prev = new_Node;
            else
                tail = new_Node;

            temp -> next = new_Node;
        }
    }

    cout << "\nFinal List:\n";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp -> data;
        temp = temp -> next;
    }
    cout << "NULL\n";

    return 0;
}