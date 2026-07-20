#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    if(!(cin >> n) || n < 0){
        cout << "Invalid input";
        return 0;
    }

    vector <vector<int>> dist(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> dist[i][j];
        }
    }

    for(int k = 0; k < n; k++){

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(dist[i][k] != 9999 && dist[k][j] != 9999 && dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j] != 9999){
                cout << dist[i][j] << " ";
            }

            else{
                cout << "INF" << " ";
            }
        }
        cout << endl;
    }
}