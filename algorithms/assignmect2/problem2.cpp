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

vector<vector<pair<int, int>>> adj;
vector<vector<long long>> shortest_paths;

void dijkstra(int src, int n)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n + 1, INF);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [curDist, u] = pq.top();
        pq.pop();

        if (curDist > dist[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    shortest_paths[src] = dist;
}

int main()
{
    int N, E;
    cin >> N >> E;

    adj.resize(N + 1);
    shortest_paths.assign(N + 1, vector<long long>(N + 1, -1));

    for (int i = 0; i < E; i++)
    {
        int A, B, W;
        cin >> A >> B >> W;
        adj[A].push_back({B, W});
    }

    int Q;
    cin >> Q;

    while (Q--)
    {
        int X, Y;
        cin >> X >> Y;

        if (shortest_paths[X][Y] == -1)
        {
            dijkstra(X, N);
        }

        long long result = shortest_paths[X][Y];
        cout << (result == INF ? -1 : result) << endl;
    }

    return 0;
}
