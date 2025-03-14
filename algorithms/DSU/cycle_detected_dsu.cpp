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
    int x_set = find(parent[x], parent);
    parent[x] = x_set;
    return x_set;
};

bool isCycle = false;
void union_op(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int x_set = find(x, parent);
    int y_set = find(y, parent);
    if (x_set == y_set)
    {
        isCycle = true;
        return;
    }
    if (rank[x_set] < rank[y_set])
    {
        parent[x_set] = y_set;
        rank[y_set] += rank[x_set];
    }
    else
    {
        parent[y_set] = x_set;
        rank[x_set] += rank[y_set];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> parent(n, -1);
    vector<int> rank(n, 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        union_op(x, y, parent, rank);
    }
    if (isCycle)
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        cout << "No Cycle Detected" << endl;
    }
    return 0;
}
