#include<iostream>
using namespace std;


void bfs(int stNode, vector<vector<int>> &graph, int v){
    vector<bool> visited(v, false);
    queue<int> q;
    visited[stNode] = true;
    q.push(stNode);
    cout << "Nodes reachable \n";
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int neighbour: graph[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

int main(){

    int v, e;
    cout << "enter number of vertices: ";
    cin >> v;
    vector<vector<int>> graph(v);

    cout << "enter number of edges: ";
    cin >> e;

    for(int i = 0; i<e; i++){
        int v, u;
        cin >> v, u;

        // undirectd graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << endl << "graph representation : "<< endl;
    for(int i = 0; i<v; i++){
        cout << i << ": ";
        for(int neighbour : graph[i]){
            cout << neighbour << "";

        }
        cout << endl;
    }
    cout << endl;
    int stNode;
    cout << endl << "enter starting Node: ";
    cin >> stNode;
    cout << endl;
    bfs(stNode, graph, v);

return 0;
}