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

vector<int> vertices[1005];
int visted[1005];
int level[1005];
int parents[1004];

// dfs node
void dfs(int src)
{
    queue<int> q;
    q.push(src);
    visted[src] = 1;
    level[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : vertices[parent])
        {
            if (!visted[child])
            {
                q.push(child);
                visted[child] = 1;
                level[child] = level[parent] + 1;
                parents[child] = parent;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int x, y;
        cin >> x >> y;
        vertices[x].push_back(y);
        vertices[y].push_back(x);
    }

    memset(visted, 0, sizeof(visted));
    memset(level, -1, sizeof(level));
    memset(parents, -1, sizeof(parents));

    int s, d;
    cin >> s >> d;
    dfs(s);

    cout << "destination Node : -> " << level[d] << endl;

    cout << "paths" << " ";
    int node = d;
    while (node != -1)
    {
        cout << node << " ";
        node = parents[node];
    }

    cout << endl;

    return 0;
}
