#include <iostream>
#include <vector>
#include <algorithm>
#include <locale.h>
using namespace std;

class Solution
{
public:
    vector<vector<bool>> vis;
    int r, c;
    int count;
    vector<pair<int, int>> movement = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    bool valid(int i, int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    void dfs(int si, int sj, vector<vector<int>> &grid)
    {
        vis[si][sj] = true;
        count++;
        for (auto [di, dj] : movement)
        {
            int ci = si + di;
            int cj = sj + dj;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
            {
                dfs(ci, cj, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        r = grid.size();
        c = grid[0].size();
        vis.assign(r, vector<bool>(c, false));
        int max_area = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    count = 0;
                    dfs(i, j, grid);
                    max_area = max(max_area, count);
                }
            }
        }

        return max_area;
    }
};

int main()
{
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter the grid values (0 or 1):" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    int result = sol.maxAreaOfIsland(grid);
    cout << "The maximum area of the island is: " << result << endl;

    return 0;
}
