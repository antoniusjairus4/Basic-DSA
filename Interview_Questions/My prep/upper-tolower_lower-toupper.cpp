#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    bool has_upper = false;
    bool has_lower = false;

    for(char c : s){
        if(isupper(c)){
            has_upper = true;
        }

        if(islower(c)){
            has_lower = true;
        }
    }

    if(!has_lower || !has_upper){
        cout << "Invalid input" << endl;
        return 0;
    }

    for(char c : s){
        if(isupper(c)){
            cout << tolower(c);
        }

        else if(islower(c)){
            cout << toupper(c);
        }

        else{
            cout << c;
        }
    }

    return 0;
}