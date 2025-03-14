#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Edge
{
public:
    int src, dest, weight;
};

// vector<Edge> edgeList; // use class Edge
vector<tuple<int, int, int>> edgeList; // use tuple instead of class Edge

vector<int> dis;
int r, c;

bool isCycle = false;

void bell_ford(int src)
{
    dis[src] = 0;
    for (int i = 0; i < r - 1; i++)
    {
        for (auto [n, s, w] : edgeList)
        {
            if (dis[n] != numeric_limits<int>::max() && dis[n] + w < dis[s])
            {
                dis[s] = dis[n] + w;
            }
        }
    }

    for (auto [n, s, w] : edgeList)
    {
        if (dis[n] != numeric_limits<int>::max() && dis[n] + w < dis[s])
        {
            isCycle = true;
            dis[s] = dis[n] + w;
        }
    }

    cout << endl;
    if (isCycle)
        cout << "There have negative weight cycle" << endl;
    else
    {
        cout << "Vertex  Distance from Source" << endl;
        for (int i = 0; i < r; i++)
        {
            cout << i << "  " << (dis[i] == numeric_limits<int>::max() ? "INF" : to_string(dis[i])) << endl;
        }
    }
}

int main()
{
    cin >> r >> c;
    dis.assign(r, numeric_limits<int>::max());

    for (int i = 0; i < c; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edgeList.push_back({x, y, z});
        // edgeList.push_back({y, x, z});
    }
    bell_ford(0);

    return 0;
}
