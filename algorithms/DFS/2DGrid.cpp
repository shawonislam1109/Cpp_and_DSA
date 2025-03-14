#include <iostream>
#include <vector>
using namespace std;

char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int, int>> movement2d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// Check if the row and column are valid
bool valid(int ci, int cj, int n, int m)
{
    return !(ci < 0 || ci >= n || cj < 0 || cj >= m);
}

void dfs(int si, int sj, int n, int m)
{
    // Mark the cell as visited
    visited[si][sj] = true;

    // Debug: Print the current cell
    cout << si << " " << sj << endl;

    // Explore adjacent cells
    for (int i = 0; i < 4; i++)
    {
        int ci = si + movement2d[i].first;
        int cj = sj + movement2d[i].second;

        // Check if the cell is valid and not visited
        if (valid(ci, cj, n, m) && !visited[ci][cj])
        {
            dfs(ci, cj, n, m);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    // Input the grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;

    // Check if the starting point is valid
    if (!valid(si, sj, n, m))
    {
        cout << "Invalid starting point" << endl;
        return 0;
    }

    // Run DFS from the starting point
    dfs(si, sj, n, m);

    return 0;
}
