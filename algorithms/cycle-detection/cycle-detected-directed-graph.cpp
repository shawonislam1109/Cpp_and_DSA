// stdc++.h
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <functional>
#include <utility>
#include <iomanip>
#include <fstream>
#include <list>
// Add other commonly used headers as needed
using namespace std;
vector<vector<int>> adjacencyList;
vector<int> visited;
vector<int> path;
bool cycle = false;

void dfs(int src)
{
    visited[src] = 1;
    path[src] = 1;

    for (int child : adjacencyList[src])
    {
        if (!visited[child])
        {
            visited[child] = 1;
            path[src] = 1;
            dfs(child);
            path[src] = 0;
        }
        else if (path[src] && visited[src])
            cycle = true;
    }
}

int main()
{

    int r, c;
    cin >> r >> c;
    adjacencyList.resize(r);
    visited.resize(r, 0);
    path.resize(r, 0);

    // while for adjacencyList
    while (c--)
    {
        int x, y;
        cin >> x >> y;
        adjacencyList[x].push_back(y);
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
