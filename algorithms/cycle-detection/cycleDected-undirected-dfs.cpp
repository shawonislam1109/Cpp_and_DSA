#include <iostream>
#include <vector>
using namespace std;

vector<int> visited;
vector<vector<int>> adjacencyList;
vector<int> parent;
bool cycle = false;

void dfs(int src)
{
    visited[src] = true;
    for (int child : adjacencyList[src])
    {
        if (!visited[child])
        {
            parent[child] = src;
            dfs(child);
        }

        else if (parent[src] != child)
        {
            cycle = true;
        }
    }
}

int main()
{
    int r, c;
    cin >> r >> c;
    adjacencyList.resize(r);
    parent.resize(r, -1);
    visited.resize(r, 0);

    while (c--)
    {
        int x, y;
        cin >> x >> y;
        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x);
    }

    for (int i = 0; i < r; i++)
    {
        if (!visited[i])
            dfs(i);
    }

    if (cycle)
        cout << "Cycle detected" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}
