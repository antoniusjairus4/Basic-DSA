#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    for(char c : s){
        if(!isalpha(c)){
            cout << "Invalid Input" << endl; 
            return 0;
        }
    }

    if(s.length() == 0){
        cout << 0 << endl;
        return 0;
    }

    int n = s.length();
    int str[100005]; 

    str[0] = 0;
    int len = 0; 
    int i = 1;

    while(i < n){
        if(s[i] == s[len]){
            len++;
            str[i] = len; 
            i++;
        }
        else{
            if(len != 0){
                len = str[len - 1];
            }
            else{
                str[i] = 0;
                i++;
            }
        }
    }

    int max_len = str[n - 1];

    while(max_len > n / 2){
        max_len = str[max_len - 1];
    }

    cout << max_len << endl;
    
    return 0;
}