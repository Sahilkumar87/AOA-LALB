#include<iostream>
#include<vector>
using namespace std;

class WeightedGraph{
    public:
    int V, E;



    // Weighted Directed Graph using Adjacency List
    void WeightedDirectedList()
    {
        cout << "Enter vertices and edges for weighted Directed Graph: ";
        cin >> V >> E;

        vector<pair<int,int>> AdjList[V];

        cout << "Enter (u v weight):\n";

        for(int i = 0; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            AdjList[u].push_back({v, w});
        }

        cout << "\nDirected Graph Adjacency List\n";

        for(int i = 0; i < V; i++)
        {
            cout << i << " -> ";

            for(auto x : AdjList[i])
            {
                cout << "(" << x.first << "," << x.second << ") ";
            }

            cout << endl;
        }
    }

    // Weighted Undirected Graph using Adjacency List
    void WeightedUndirectedList()
    {
        cout << "\nEnter vertices and edges for weighted Undirected Graph: ";
        cin >> V >> E;

        vector<pair<int,int>> AdjList[V];

        cout << "Enter (u v weight):\n";

        for(int i = 0; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            AdjList[u].push_back({v, w});
            AdjList[v].push_back({u, w});
        }

        cout << "\nUndirected Graph Adjacency List\n";

        for(int i = 0; i < V; i++)
        {
            cout << i << " -> ";

            for(auto x : AdjList[i])
            {
                cout << "(" << x.first << "," << x.second << ") ";
            }

            cout << endl;
        }
    }
};

int main()
{
    WeightedGraph wg;

    wg.WeightedDirectedList();

    cout << endl;

    wg.WeightedUndirectedList();

    return 0;
}