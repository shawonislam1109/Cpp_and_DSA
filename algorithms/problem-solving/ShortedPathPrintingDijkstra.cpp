#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
#define ll long long int

vector<vector<pair<ll, ll>>> adjacencyList;
vector<ll> dis;
vector<ll> parent;

void dijkstra(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dis[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [par_d, par_n] = pq.top();
        pq.pop();

        if (par_d > dis[par_n])
            continue;

        for (auto [child_n, child_d] : adjacencyList[par_n])
        {
            ll total_d = par_d + child_d;
            if (dis[child_n] > total_d)
            {
                dis[child_n] = total_d;
                parent[child_n] = par_n;
                pq.push({total_d, child_n});
            }
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;

    adjacencyList.resize(n + 1);
    parent.assign(n + 1, -1);
    dis.assign(n + 1, numeric_limits<ll>::max());

    for (ll i = 0; i < m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        adjacencyList[x].push_back({y, z});
        adjacencyList[y].push_back({x, z});
    }
    dijkstra(1);

    if (dis[n] == numeric_limits<int>::max())
    {
        cout << "-1" << endl;
    }
    else
    {
        ll node = n;
        while (node != -1)
        {
            cout << node << " ";
            node = parent[node];
        }
    }

    return 0;
}
