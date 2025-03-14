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
#define INF 1e18

struct Edge
{
    int u, v;
    long long w;
};

vector<Edge> edges;
vector<long long> dist;
int N, E;

bool bellman_ford(int src)
{
    dist.assign(N + 1, INF);
    dist[src] = 0;

    for (int i = 1; i < N; i++)
    {
        bool updated = false;
        for (auto [u, v, w] : edges)
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

    for (auto [u, v, w] : edges)
    {
        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            return true;
        }
    }

    return false;
}

int main()
{

    cin >> N >> E;
    edges.resize(E);

    for (int i = 0; i < E; i++)
    {
        int A, B;
        long long W;
        cin >> A >> B >> W;
        edges[i] = {A, B, W};
    }

    int S;
    cin >> S;

    if (bellman_ford(S))
    {
        cout << "Negative Cycle Detected\n";
        return 0;
    }

    int T;
    cin >> T;
    while (T--)
    {
        int D;
        cin >> D;
        if (dist[D] == INF)
            cout << "Not Possible" << endl;
        else
            cout << dist[D] << endl;
    }

    return 0;
}
