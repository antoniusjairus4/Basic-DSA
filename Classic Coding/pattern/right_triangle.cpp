#include <iostream>
#include <string>

using namespace std;

void right_triangle(int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            cout << "*";
        }

        cout << endl;
    }
}

int main()
{
    int n;
    if(!(cin >> n) || n < 1){
        cout << "Cannot form a triangle";
        return 0;
    }

    right_triangle(n);

    return 0;
}