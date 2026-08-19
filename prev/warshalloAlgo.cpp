#include <iostream>
using namespace std;

int main()
{
    int V = 4;

    int reach[4][4] =
    {
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        {0,0,0,0}
    };

    for(int k = 0; k < V; k++)
    {
        for(int i = 0; i <  V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                // Already connected?
                reach[i][j] =
                    reach[i][j] || // Already connected
                    
                    // Can k reach j?
                    // Can I go i → k AND k → j ?
                    (reach[i][k] && reach[k][j]);
                    

                // Keep the old answer OR find a new path through k.
            }
        }
    }

    cout << "Transitive Closure Matrix\n";

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
            cout << reach[i][j] << " ";

        cout << endl;
    }

    return 0;
}

// | Case                | Time Complexity | Space Complexity | Reason                                                                             |
// | ------------------- | --------------- | ---------------- | ---------------------------------------------------------------------------------- |
// | **Best Case**       | **O(V³)**       | **O(V²)**        | All three loops (`k`, `i`, `j`) execute completely even if the graph has no edges. |
// | **Average Case**    | **O(V³)**       | **O(V²)**        | Every vertex is still considered as an intermediate for every pair of vertices.    |
// | **Worst Case**      | **O(V³)**       | **O(V²)**        | Even if the graph is fully connected, all iterations are performed.                |
// | **Auxiliary Space** | **—**           | **O(1)**         | Only loop variables (`i`, `j`, `k`) are used apart from the matrix.                |


//Warshell algorithm