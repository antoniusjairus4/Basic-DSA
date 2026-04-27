#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = nullptr;
        }
};

class Stack {
    Node *top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);

        if (!newNode) {
            cout << "Stack Overflow" << endl;
            return;
        }

        newNode -> next = top;
        top = newNode;

        cout << x << " pushed" << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow" << endl;
            return;
        }

        Node* temp = top;
        cout << temp -> data << " popped" << endl;
        top = top -> next;
        delete temp;
    }

    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Top: " << top -> data << endl;
    }

    void isEmpty() {
        if (top == nullptr)
            cout << "Stack is empty" << endl;
        else
            cout << "Stack is not empty" << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of operations: ";
    cin >> n;

    Stack st;

    string cmd;
    
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        
        if (cmd == "push") {
            int value;
            cin >> value;
            st.push(value);
        }

        else if (cmd == "pop") {
            st.pop();
        }
        else if (cmd == "peek") {
            st.peek();
        }
        else if (cmd == "empty") {
            st.isEmpty();
        }
        else if (cmd == "end") {
            break;
        }
        else {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}