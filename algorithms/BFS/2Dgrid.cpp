#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int grid[1005][1005];
bool visited[1005][1005];
int level[1005][1005];
int row, col;

// Movement directions (up, right, down, left)
vector<pair<int, int>> keyValue = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// Check if the cell is within bounds
bool valid(int i, int j)
{
    if (i < 0 || i >= row || j < 0 || j >= col)
        return false;
    else
        return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        // Print the current cell (for debugging if needed)
        cout << "Processing: " << par.first << " " << par.second << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + keyValue[i].first;
            int cj = par.second + keyValue[i].second;

            // Check if the cell is valid and not visited
            if (valid(ci, cj) && !visited[ci][cj])
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[par.first][par.second] + 1;
            }
        }
    }
}

int main()
{
    // Input grid dimensions
    cin >> row >> col;

    // Input grid values
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
        }
    }

    // Initialize the visited and level arrays
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));

    // Input the starting and destination points
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    // Run BFS from the starting point
    bfs(si, sj);

    // Output the level (distance) of the destination point
    if (level[di][dj])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
