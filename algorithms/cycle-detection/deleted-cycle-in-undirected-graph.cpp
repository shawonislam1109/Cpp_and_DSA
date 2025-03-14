#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> vis;
vector<vector<int>> adjacencyList;
vector<int> parent;
bool cycle = false;

void bfs(int src)
{
    vis[src] = true;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : adjacencyList[par])
        {
            if (!vis[child])
            {
                vis[child] = true;
                parent[child] = par;
                q.push(child);
            }
            else if (vis[child] && parent[par] != child)
            {
                cycle = true;
            }
        }
    }
}

int main()
{
    int r, c;
    cin >> r >> c;
    vis.resize(r, 0);
    parent.resize(r, -1);
    adjacencyList.resize(r);

    while (c--)
    {
        int x, y;
        cin >> x >> y;
        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x);
    }

    // print adjacency list
    for (int i = 0; i < r; i++)
    {
        cout << i << " -> ";
        for (int j : adjacencyList[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    // for (int i = 0; i < r; i++)
    // {
    //     if (!vis[i])
    //         bfs(i);
    // }

    if (cycle)
        cout << "Cycle detected" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}
