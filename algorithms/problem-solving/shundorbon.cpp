#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> shundorbon;
vector<vector<int>> visited;
vector<vector<int>> level;
vector<pair<int, int>> movement = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int n;

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < n;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    visited[si][sj] = 1;
    level[si][sj] = 0;
    q.push({si, sj});

    while (!q.empty())
    {
        auto [dx, dy] = q.front();
        q.pop();

        for (auto [child_x, child_y] : movement)
        {
            int ci = dx + child_x;
            int cj = dy + child_y;

            if (valid(ci, cj) && !visited[ci][cj] && shundorbon[ci][cj] != 'T')
            {
                visited[ci][cj] = 1;
                level[ci][cj] = level[dx][dy] + 1;
                q.push({ci, cj});
            }
        }
    }
}

int main()
{
    cin >> n;
    int si, sj, di, dj;
    shundorbon.resize(n, vector<char>(n));
    visited.assign(n, vector<int>(n, 0));
    level.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> shundorbon[i][j];
            if (shundorbon[i][j] == 'S')
            {
                si = i;
                sj = j;
            }
            if (shundorbon[i][j] == 'E')
            {
                di = i;
                dj = j;
            }
        }
    }

    bfs(si, sj);

    if (visited[di][dj])
        cout << level[di][dj] << endl;
    else
        cout << "-1" << endl;

    return 0;
}
