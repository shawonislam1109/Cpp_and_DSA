#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
vector<vector<pair<int, int>>> adjacencyList;
vector<int> vertices;

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vertices[src] = 0;
    pq.push({src, 0});

    while (!pq.empty())
    {
        auto [parNode, parDist] = pq.top();
        pq.pop();

        if (parDist > vertices[parNode])
            continue;

        for (auto [childNode, childDist] : adjacencyList[parNode])
        {
            int shortedWeight = parDist + childDist;
            if (vertices[childNode] > shortedWeight)
            {
                vertices[childNode] = shortedWeight;
                pq.push({childNode, shortedWeight});
            }
        }
    }
}

int main()
{
    int r, c;
    cin >> r >> c;
    adjacencyList.resize(r);
    vertices.resize(r, numeric_limits<int>::max());

    while (c--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adjacencyList[x].push_back({y, z});
        adjacencyList[y].push_back({x, z});
    }

    int s, d;
    cin >> s >> d;

    dijkstra(s);

    for (int i = 0; i < r; i++)
    {
        cout << "Shortest Path from " << s << " to " << i << " : " << vertices[i] << endl;
    }

    return 0;
}
