#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<int>> grid;
vector<vector<int>> visited;
vector<pair<int, int>> movement = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<pair<int, int>> land;
int r, c;

// Check if the row and column are valid
bool valid(int ci, int cj)
{
    return ci >= 0 && ci < r && cj >= 0 && cj < c;
}

void dfs(int si, int sj)
{
    visited[si][sj] = true;
    land.push_back({si, sj});

    for (int i = 0; i < 4; i++)
    {
        int ci = si + movement[i].first;
        int cj = sj + movement[i].second;

        if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] != 0)
        {
            visited[ci][cj] = true;
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> r >> c;

    int count = 0;

    grid.resize(r, vector<int>(c));
    visited.resize(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] != 0 && !visited[i][j])
            {
                dfs(i, j);
                for (auto p : land)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        int ci = p.first + movement[i].first;
                        int cj = p.second + movement[i].second;
                        if (!valid(ci, cj) || grid[ci][cj] == 0)
                        {
                            count++;
                        }
                    }
                }
                cout << endl;
            }
        }
    }

    cout << count << endl;

    return 0;
}
