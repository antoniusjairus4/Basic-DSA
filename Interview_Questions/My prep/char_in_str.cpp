#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    if(s.empty()){
        cout << "Invalid input" << endl;
        return 0;
    }

    map <char, int> freq_map;
    for(char c : s){

        if(isalpha(c)){
            freq_map[c]++;
        }

        else if(isspace(c)){
            continue;
        }

        else{
            cout << "Invalid input" << endl;
            return 0;
        }
    }

    cout << "Character Frequencies:" << endl;

    for(auto const &pair : freq_map){
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}