#include <iostream>
#include <string>

using namespace std;

class data {
    public:
        string name;
        string dept;
        int marks;
};

class operation : public data {
    public:
        void result() {
            if (marks < 50) {
                cout << "Arrear brooo";
            }
            else if (marks >= 50 && marks <= 60) {
                cout << "Pass";
            }
            else if (marks > 60 && marks < 80) {
                cout << "Good";
            }
            else if (marks >= 80 && marks < 100) {
                cout << "Distinction";
            }
            else if (marks == 100) {
                cout << "Centum aahhhhh";
            }
        }
};

int main() {
        int n;
        cout << "Enter the number of Students: ";
        cin >> n;

        operation s[n];

        for (int i = 1; i < n + 1; i++) 
        {
            cout << endl << "Enter the details for student " << i << endl;
            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, s[i].name);

            cout << "Enter Department: ";
            getline(cin, s[i].dept);

            cout << "Enter Marks: ";
            cin >> s[i].marks;
        }

        for (int i = 0; i < n; i++) {

            cout << "Student " << i + 1 << endl;
            cout << "Name: " << s[i].name << endl;

            cout << "Department: " << s[i].dept << endl;
            cout << "Marks: " << s[i].marks << endl;
            
            cout << "Result: ";
            s[i].result();

            cout << endl << endl;
        }

    return 0;
}