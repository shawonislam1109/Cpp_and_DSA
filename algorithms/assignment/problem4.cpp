#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int n, m;
vector<string> grid;
bool visited[1005][1005];
vector<pair<int, int>> movement2D = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int dfs(int x, int y)
{
    visited[x][y] = true;
    int size = 1;

    for (int i = 0; i < 4; i++)
    {
        int ci = x + movement2D[i].first;
        int cj = y + movement2D[i].second;

        if (ci >= 0 && ci < n && cj >= 0 && cj < m && grid[ci][cj] == '.' && !visited[ci][cj])
        {
            size += dfs(ci, cj);
        }
    }
    return size;
}

int main()
{
    cin >> n >> m;
    grid.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    memset(visited, false, sizeof(visited));
    vector<int> dotCounts;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                int dotsInComponent = dfs(i, j);
                dotCounts.push_back(dotsInComponent);
            }
        }
    }

    sort(dotCounts.begin(), dotCounts.end());
    for (int count : dotCounts)
    {
        cout << count << " ";
    }
    cout << endl;
    return 0;
}
