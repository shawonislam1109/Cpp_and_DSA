#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> adjacencyList[1005];
bool vis[1005];

// BFS traversal
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        cout << f << " ";

        // Use adjacencyList[f] to explore neighbors of the current node
        for (int x : adjacencyList[f])
        {
            if (!vis[x])
            {
                q.push(x);
                vis[x] = true;
            }
        }
    }
}

int main()
{
    int N, edge;
    cin >> N >> edge;

    // Input edges and construct the adjacency list
    while (edge--)
    {
        int x, y;
        cin >> x >> y;
        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x);
    }

    memset(vis, false, sizeof(vis));
    bfs(1);
    return 0;
}
