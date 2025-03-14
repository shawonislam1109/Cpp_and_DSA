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

vector<int> adjacencyList[105];
int visited[105];

void dfs(int src)
{

    cout << src << " ";
    visited[src] = true;
    for (int child : adjacencyList[src])
        if (!visited[child])
            dfs(child);
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int x, y;
        cin >> x >> y;
        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x);
    }

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            cout << endl;
        }
    }

    return 0;
}
