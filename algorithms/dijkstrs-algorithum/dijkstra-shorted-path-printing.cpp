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

vector<vector<pair<int, int>>> adjacencyMatrix;
vector<int> vertices;
vector<pair<int, int>> parent;

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vertices[s] = 0;
    pq.push({s, 0});
    while (!pq.empty())
    {
        auto [parNode, parDist] = pq.top();
        pq.pop();

        if (parDist > vertices[parNode])
            continue;

        for (auto [childNode, childDist] : adjacencyMatrix[parNode])
        {
            if (vertices[childNode] > childDist + parDist)
            {
                vertices[childNode] = childDist + parDist;
                parent[childNode] = {parNode, childDist};
                pq.push({childNode, childDist + parDist});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    adjacencyMatrix.resize(n, vector<pair<int, int>>(m));
    vertices.resize(n, numeric_limits<int>::max());
    parent.resize(n);

    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adjacencyMatrix[x].push_back({y, z});
        adjacencyMatrix[y].push_back({x, z});
    }

    int src;
    cin >> src;

    dijkstra(src);

    for (int i = 0; i < adjacencyMatrix.size(); i++)
    {
        cout << "Shortest dist " << src << " to " << i << " : " << vertices[i] << endl;
    }

    cout << endl;
    cout << endl;
    cout << "shorted path printing" << endl;

    for (int i = 0; i < parent.size(); i++)
    {
        cout << "Shortest Path form " << src << " to " << i << " : ";
        stack<int> path;

        int node = i;
        while (node != src)
        {
            path.push(node);
            node = parent[node].first;
        }
        path.push(src);
        while (!path.empty())
        {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }

    return 0;
}
