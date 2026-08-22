#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector <int> a, vector <int> b){
    return a[2] < b[2];
}

int find_parent(int x){
    if(parent[x] == x){
        return x;
    }

    return parent[x] = find_parent(parent[x]);
}

void union_set(int x, int y){
    int px = find_parent(parent[x]);
    int py = find_parent(parent[y]);
    parent[px] = py;
}

vector <int> parent;
int main()
{
    int V, E;
    cin >> V >> E;

    if(V <= 0 || E <= 0){
        cout << "Invalid input";
    }

    vector <vector <int>> graph;

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u, v, w;

        graph.push_back({u, v, w});
    }

    parent.resize(V);
    for(int i = 0; i < V; i++){
        parent[i] = i;
    }

    sort(graph.begin(), graph.end(), compare);

    int cost = 0;
    for(int i = 0; i < E; i++){
        int u = graph[i][0];
        int v = graph[i][1];
        int w = graph[i][2];

        if(find_parent(u) != find_parent(v)){
            cost += w;
            union_set(u, v);
        }
    }

    cout << cost;
}