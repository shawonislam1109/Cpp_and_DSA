#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<vector<long long int>> adjacencyMatrix;
long long int n, e, q;

// Floyd-Warshall Algorithm
void floydWarshall()
{
    for (long long int k = 0; k < n; k++)
    {
        for (long long int i = 0; i < n; i++)
        {
            for (long long int j = 0; j < n; j++)
            {
                // Check if paths are valid before adding (avoid overflow)
                if (adjacencyMatrix[i][k] != numeric_limits<long long int>::max() &&
                    adjacencyMatrix[k][j] != numeric_limits<long long int>::max() &&
                    adjacencyMatrix[i][k] + adjacencyMatrix[k][j] < adjacencyMatrix[i][j])
                {
                    adjacencyMatrix[i][j] = adjacencyMatrix[i][k] + adjacencyMatrix[k][j];
                }
            }
        }
    }
}

int main()
{
    cin >> n >> e >> q;

    // Resize adjacency matrix with large values
    adjacencyMatrix.assign(n, vector<long long int>(n, numeric_limits<long long int>::max()));

    // Initialize diagonal to 0 (no self-loop cost)
    for (long long int i = 0; i < n; i++)
    {
        adjacencyMatrix[i][i] = 0;
    }

    // Read edges
    for (long long int i = 0; i < e; i++)
    {
        long long int x, y, z;
        cin >> x >> y >> z;
        adjacencyMatrix[x][y] = z;
        adjacencyMatrix[y][x] = z; // Undirected graph
    }

    // Run Floyd-Warshall Algorithm
    floydWarshall();

    // Process queries
    for (long long int i = 0; i < q; i++)
    {
        long long int x, y;
        cin >> x >> y;

        if (adjacencyMatrix[x][y] == numeric_limits<long long int>::max())
            cout << "-1" << endl; // No path
        else
            cout << adjacencyMatrix[x][y] << endl;
    }

    return 0;
}
