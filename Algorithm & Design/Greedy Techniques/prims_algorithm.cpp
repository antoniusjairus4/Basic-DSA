#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    if(v <= 0|| e < 0){
        cout << "Invalid input";
        return 0;
    }

    vector <vector <int> > graph(v,vector <int> (v, 0));

    for(int i = 0; i < e; i++){
       int u, v, w;

        cin >> u >> v >> w;

        graph [u][v] = w;
        graph [v][u] = w;
    }

    int edge = 0;
    int totalcost = 0;

    vector <bool> visited (v, false);

    visited [0] = true;

    while(edge < v-1)
    {
        int mn = INT_MAX;
        int x = -1, y = -1;

        for(int i = 0; i < v; i++){

            if(visited[i] == true){

                for(int j = 0; j < v; j++){
                    if(!visited[j] && graph[i][j] != 0){
                        if(graph[i][j] < mn){
                            mn = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        
        if(x == -1 || y == -1){
            break;
        }

        visited[y] = true;
        totalcost += mn;
        edge++;
    }

    cout<<totalcost;
}