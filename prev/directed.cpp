#include<iostream>
#include <vector>

using namespace std;

class UnWeightedGraph{
    int V, E;

public:

    void WeightedDirectedMatrix()
    {
        cout << "Enter vertices and edges for Directed Graph: ";
        cin >> V >> E;

        vector<vector<int>> Admat(V, vector<int>(V, 0));

        cout << "Enter (u v):\n";

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;

            Admat[u][v] = 1;
        }

        cout << "\nDirected Graph Adjacency Matrix\n";

        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                cout << Admat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void wightedUndirectedMatrix()
    {
        cout << "\nEnter vertices and edges for Undirected Graph: ";
        cin >> V >> E;

        vector<vector<int>> Admat(V, vector<int>(V, 0));

        cout << "Enter (u v):\n";

        for(int i = 0; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v, w;

            Admat[u][v] = w;
            Admat[v][u] = w;
        }

        cout << "\nUndirected Graph Adjacency Matrix\n";

        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                cout << Admat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    UnWeightedGraph wg;

    wg.WeightedDirectedMatrix();

    cout << endl;

    wg.wightedUndirectedMatrix();

    return 0;
}