#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    for(char c : s){
        if(isdigit(c)){
            cout << "Invalid Input" << endl;
            return 0;
        }
    }

    for(char c : s){
        if(islower(c)){
            char mirror = 'z' - (c - 'a');
            cout << mirror;
        }
        else{
            cout << c;
        }
    }
    
    return 0;
}