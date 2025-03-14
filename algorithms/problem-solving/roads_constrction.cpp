#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findParent(int child, vector<int> &parent)
{
    if (parent[child] == -1)
        return child;
    return parent[child] = findParent(parent[child], parent);
}

void union_on(int x, int y, vector<int> &parent, vector<int> &size, int &maxComponent, int &totalComponents)
{
    int node1 = findParent(x, parent);
    int node2 = findParent(y, parent);

    if (node1 != node2)
    {
        totalComponents--;

        if (size[node1] < size[node2])
        {
            parent[node1] = node2;
            size[node2] += size[node1];
            maxComponent = max(maxComponent, size[node2]);
        }
        else
        {
            parent[node2] = node1;
            size[node1] += size[node2];
            maxComponent = max(maxComponent, size[node1]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1, -1);
    vector<int> size(n + 1, 1);

    int maxComponent = 1;
    int totalComponents = n;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        union_on(x, y, parent, size, maxComponent, totalComponents);
        cout << totalComponents << " " << maxComponent << endl;
    }

    return 0;
}
