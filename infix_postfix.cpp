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
            
        }
};

int main()
{
    return 0;
}