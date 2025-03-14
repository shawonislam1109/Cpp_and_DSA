#include <iostream>
using namespace std;

int main()
{
    int N, edge;
    cin >> N >> edge;

    int matrixUndirected[N][N];
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         matrixUndirected[i][j] = 0;
    //     }
    // }
    memset(matrixUndirected, 0, sizeof(matrixUndirected));

    for (int i = 0; i < edge; i++)
    {
        int x, y;
        cin >> x >> y;
        if ((x + y) / 2 == 0)
        {
            matrixUndirected[x][y] = 1;
        }
        else
        {
            matrixUndirected[x][y] = 1;
            matrixUndirected[y][x] = 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrixUndirected[i][j])
            {
                cout << i << " " << j << ": " << matrixUndirected[i][j] << endl;
            }
        }
    }

    return 0;
}
