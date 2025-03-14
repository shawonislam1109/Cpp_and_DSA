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

int find(int x, vector<int> &parent)
{
    if (parent[x] == -1)
    {
        return x;
    }
    int findPar = find(parent[x], parent);
    parent[x] = findPar;
    return findPar;
}

void union_on(int x, int y, vector<int> &parent, vector<int> &size)
{
    int node1 = find(x, parent);
    int node2 = find(y, parent);

    if (size[node1] < size[node2])
    {
        parent[node1] = node2;
        size[node2] += size[node1];
    }
    else
    {
        parent[node2] = node1;
        size[node1] += size[node2];
    }
}

int main()
{
    int n;
    cin >> n;
    int cycleCount = 0;
    vector<pair<int, int>> removeNodes;
    vector<pair<int, int>> createNode;
    vector<int> parent(n + 1, -1);
    vector<int> rank(n + 1, 1);

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        int node1 = find(x, parent);
        int node2 = find(y, parent);
        if (node1 == node2)
        {
            cycleCount++;
            removeNodes.push_back({x, y});
        }
        else
        {
            union_on(x, y, parent, rank);
        }
    }

    for (int i = 2; i < n; i++)
    {
        int node1 = find(1, parent);
        int node2 = find(i, parent);
        if (node1 != node2)
        {
            union_on(1, i, parent, rank);
            createNode.push_back({1, i});
        }
    }

    cout << cycleCount << endl;
    for (auto [x, y] : removeNodes)
    {
        cout << x << " " << y << " ";
    }
    for (auto [x, y] : createNode)
    {
        cout << x << " " << y << " ";
    }
    return 0;
}
