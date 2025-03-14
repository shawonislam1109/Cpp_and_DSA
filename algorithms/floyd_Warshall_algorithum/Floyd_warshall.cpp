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
int n, e;
vector<vector<int>> adjacencyMatrix;

int main()
{
    cin >> n >> e;
    adjacencyMatrix.assign(n, vector<int>(e, numeric_limits<int>::max()));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            adjacencyMatrix[x][y] = z;

            if (i == j)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < e; j++)
            {
                if (adjacencyMatrix[i][k] != numeric_limits<int>::max() && adjacencyMatrix[k][j] != numeric_limits<int>::max())
                {
                    adjacencyMatrix[i][j] = min(adjacencyMatrix[i][j], adjacencyMatrix[i][k] + adjacencyMatrix[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            if (adjacencyMatrix[i][j] == numeric_limits<int>::max())
                cout << "INT_MAX" << " ";
            else
                cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
