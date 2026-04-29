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
                return '\0';
            }

            return arr[top];
        }

        bool empty(){
            return top = -1;
        }
};

int precedence (char c){

    switch (c){
        case '+' : case '-' : return 1;
        case '*' : case '%' : return 2;
        case '^' : return 3;
        return 0;
    }
}

void convert(string s){

    Stack st(s.length());
    string res = "";

    for(char c : s){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 0 && c <= 9)){
            res += c;
        }

        else if(c == '('){
            st.push(c);
        }

        else if(c == ')'){
            while ((st.peek() != '(') && !st.empty()){
                res += st.peek();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!(st.empty()) && precedence(st.peek()) >= precedence(c)){
                res += st.peek();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!(st.empty())){
        res += st.peek();
        st.pop();
    }

    cout << "The Postfix expression is: " << res << endl;
}
int main()
{
    int n;
    cout << "Enter the number of the elements in the stack : ";
    cin >> n;

    Stack st(n);

    string s;
    cout << "Enter the infix value : ";
    getline(cin, s);

    convert (s);

    return 0;
}