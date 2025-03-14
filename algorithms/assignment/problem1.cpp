#include <iostream>
using namespace std;

int main()
{
    int N, edge;
    cin >> N >> edge;

    int matrixDirected[N][N];

    memset(matrixDirected, 0, sizeof(matrixDirected));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                matrixDirected[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < edge; i++)
    {
        int x, y;
        cin >> x >> y;

        matrixDirected[x][y] = 1;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (matrixDirected[x][y])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
