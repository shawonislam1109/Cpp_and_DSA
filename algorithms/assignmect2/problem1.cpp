#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> bellmanFord(int n, int m, vector<tuple<int, int, int>> &edges, int src, bool &hasNegativeCycle)
{
    vector<int> dist(n + 1, INF);
    dist[src] = 0;

    for (int i = 1; i < n; i++)
    {
        bool updated = false;
        for (const auto &[u, v, w] : edges)
        {
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        if (!updated)
            break;
    }

    for (const auto &[u, v, w] : edges)
    {
        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            hasNegativeCycle = true;
            break;
        }
    }

    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    int src;
    cin >> src;

    int t;
    cin >> t;

    vector<int> testCases(t);
    for (int i = 0; i < t; i++)
    {
        cin >> testCases[i];
    }

    bool hasNegativeCycle = false;
    vector<int> distances = bellmanFord(n, m, edges, src, hasNegativeCycle);

    if (hasNegativeCycle)
    {
        cout << "Negative Cycle Detected\n";
    }
    else
    {
        for (int dest : testCases)
        {
            if (distances[dest] == INF)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << distances[dest] << endl;
            }
        }
    }

    return 0;
}
