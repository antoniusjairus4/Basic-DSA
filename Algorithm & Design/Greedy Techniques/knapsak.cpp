#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item {
    int price;
    int satisfaction;
    double ratio;
};

bool compare(item a, item b){
    return a.ratio > b.ratio;
}

int main()
{
    int N;
    cin >> N;

    if (N <= 0){
        cout << "Invalid input";
        return 0;
    }

    vector <item> arr(N);

    for (int i = 0; i < N; i++){
        cin >> arr[i].price;
    }

    for (int i = 0; i < N; i++){
        cin >> arr[i].satisfaction;
    }

    int B;
    cin >> B;

    if (B < 0){
        cout << "Invalid input";
        return 0;
    }

    for(int i = 0; i < N; i++){
        arr[i].ratio = (double)arr[i].satisfaction / arr[i].price;
    }
    
    sort(arr.begin(), arr.end(), compare);

    int sum = 0;
    int totalSatisfaction=0;

    for (int i = 0; i < N; i++){
        if (arr[i].price  + sum <= B){
            sum += arr[i].price;
            totalSatisfaction += arr[i].satisfaction;
        }
    }
    cout << totalSatisfaction;
    return 0;
}