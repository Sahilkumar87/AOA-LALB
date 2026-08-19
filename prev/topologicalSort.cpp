#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int V = 6;

    vector<vector<int>> graph(V);

    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);

    vector<int> indegree(V, 0);

    // calculate indegree of every nodes
    for(int i = 0; i < V; i++)
    {
        for(int v : graph[i])
            indegree[v]++;
    }

    // | Node     | 0 | 1 | 2 | 3 | 4 | 5 |
    // | -------- | - | - | - | - | - | - |
    // | Indegree | 2 | 2 | 1 | 1 | 0 | 0 |


    queue<int> q;

    //push all nodes having indegree 0
    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    // Only nodes 4 and 5 have indegree 0.

    cout << "Topological Order : ";

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int next : graph[node])
        {
            indegree[next]--;

            if(indegree[next] == 0)
                q.push(next);
        }
    }

    return 0;
}

// Time Complexity: O(V + E) because every vertex and every 
// edge is processed at most once.
// Space Complexity: O(V + E) because the adjacency 
// list stores all vertices and edges, while indegree 
// array and queue require O(V) additional space.