#include <iostream>
#include <string>

using namespace std;

class Stack{
    int *arr;
    int top;
    int capacity;

    public:
        Stack(int size){
            capacity = size;
            arr = new int [capacity];
            top = -1;
        }

        void push(char x){
            if(top == capacity - 1){
                cout << "Stack Overflow" << endl;
                return;
            }

            arr [++top] = x;
        }

        void pop()
        {
            if(top == -1){
                cout << "Stack Underflow" << endl;
                return;
            }

            top--;
        }

        char peek(){
            if(top == -1){
                cout << "Stack is empty;" << endl;
                return;
            }

            return arr[top];
        }

        bool empty(){
            return top = -1;
        }
};

int main()
{
    return 0;
}