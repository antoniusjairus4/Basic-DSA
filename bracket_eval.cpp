#include <iostream>
#include <stack>

using namespace std;

bool valid(string s){
    stack <char> st;

    for(char c : s){
        
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        } 

        else{
            if(st.empty()){
                return false;
            }

            char top = st.top();
            st.pop();

            if((c == ')' && top != '(') || 
               (c == '}' && top != '{') ||
               (c == ']' && top != '[')){
                return false;
            }
        }
    }

    return st.empty();
}

int main()
{
    string s;
    getline(cin, s);

    if(valid(s)){
        cout << "The given sequence of Brackets are valid";
    }
    else{
        cout << "The given sequence of Brackets are not valid";
    }
    return 0;
}