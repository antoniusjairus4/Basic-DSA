#include <iostream>
#include <string>

using namespace std;

class Stack{
    char *arr;
    int top;
    int capacity;

    public:
        Stack(int size){
            capacity = size;
            arr = new char[capacity];
            top = -1;
        }

        void push(char x){
            if(top == capacity - 1){
                cout << "Stack Overflow" << endl;
                return;
            }
            arr [++top] = x;
        }

        void pop(){
            if(top == -1){
                return;
            }
            top--;
        }

        char peek(){
            if(top == -1){
                cout << "Stack is empty" << endl;
                return '%';
            }
            return arr[top];
        }

        bool empty(){
            return top == -1;
        }
};

bool valid(string s){
    
    Stack st(s.length());

    for(char c : s){
        if(c == '{' || c == '(' ||  c == '['){
            st.push(c);
        }

        else{
            if(st.empty()){
                return false;
            }

            char top = st.peek();
            st.pop();

            if((c == ')' && top != '(') || 
               (c == ']' && top != '[') || 
               (c == '}' && top != '{')){
                return false;
               }
        }
    }

    return st.empty();
}

int main()
{
    return 0;
}