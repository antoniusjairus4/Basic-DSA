#include <iostream>

using namespace std;

class MemoryUtils {

    public:
        void swap(int* a, int* b) {
            int temp = *a;
            *a = *b;
            *b = temp;
        }
};

int main() {
    MemoryUtils utils;
    int x = 10, y = 20;

    cout << "Before Swapping : x = " << x << ", y = " << y << endl;
    utils.swap(&x, &y);
    cout << "After Swapping : x = " << x << ", y = " << y << endl;

    return 0;
}