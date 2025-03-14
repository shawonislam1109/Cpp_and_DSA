#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, edge;
    cin >> N >> edge;

    vector<vector<int>> adjacencyList(N);

    while (edge--)
    {
        int x, y;
        cin >> x >> y;

        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x);
    }

    for (int i = 0; i < N; i++)
    {
        cout << "Node " << i << ":";
        for (int neighbor : adjacencyList[i])
        {
            cout << " " << neighbor;
        }
        cout << endl;
    }

    return 0;
}
