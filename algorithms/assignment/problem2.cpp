#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, edge;
    cin >> N >> edge;

    vector<vector<int>> adjacencyList(N + 1);
    while (edge--)
    {
        int x, y;
        cin >> x >> y;

        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x);
    }

    for (int i = 1; i < N; i++)
    {
        sort(adjacencyList[i].begin(), adjacencyList[i].end(), greater<int>());
    }

    int q;
    cin >> q;

    while (q--)
    {
        int queryNumber;
        cin >> queryNumber;

        if (adjacencyList[queryNumber].empty())
        {

            cout << -1 << endl;
        }
        else
        {

            for (int x : adjacencyList[queryNumber])
            {
                cout << x << " ";
            }
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}
