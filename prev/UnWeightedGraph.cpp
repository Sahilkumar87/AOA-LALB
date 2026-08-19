#include<iostream>
#include <vector>

using namespace std;

class UnWeightedGraph{
    int V, E;

public:

    void unWeightedDirectedMatrix()
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

    void unewightedUndirectedMatrix()
    {
        cout << "\nEnter vertices and edges for Undirected Graph: ";
        cin >> V >> E;

        vector<vector<int>> Admat(V, vector<int>(V, 0));

        cout << "Enter (u v):\n";

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;

            Admat[u][v] = 1;
            Admat[v][u] = 1;
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

    wg.unWeightedDirectedMatrix();

    cout << endl;

    wg.unewightedUndirectedMatrix();

    return 0;
}