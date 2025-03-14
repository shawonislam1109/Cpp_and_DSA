#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int r, c;
char grid[105][105];
int level[105][105];
bool visited[105][105];
int si, sj, di, dj;
vector<pair<int, int>> movement2D = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= r || j < 0 || j >= c)
        return false;
    return true;
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + movement2D[i].first;
            int cj = par.second + movement2D[i].second;

            if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] != '#')
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
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(level, -1, sizeof(level));
    memset(visited, false, sizeof(visited));

    bfs();

    if (level[di][dj] != -1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
