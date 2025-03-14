#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<char>> matrix;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;
vector<pair<int, int>> movement = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int r, c;
bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

bool bfs(int si, int sj, int &di, int &dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (matrix[x][y] == 'D')
        {
            di = x;
            dj = y;
            return true;
        }

        for (auto [dx, dy] : movement)
        {
            int nx = x + dx;
            int ny = y + dy;

            if (valid(nx, ny) && !visited[nx][ny] && (matrix[nx][ny] == '.' || matrix[nx][ny] == 'D'))
            {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
    return false;
}

void markPath(int di, int dj, int si, int sj)
{
    while (parent[di][dj] != make_pair(-1, -1))
    {
        auto [px, py] = parent[di][dj];
        if (matrix[px][py] == '.')
        {
            matrix[px][py] = 'X';
        }
        di = px;
        dj = py;
    }
}

int main()
{
    cin >> r >> c;

    matrix.resize(r, vector<char>(c));
    visited.resize(r, vector<bool>(c, false));
    parent.resize(r, vector<pair<int, int>>(c, {-1, -1}));

    int si = -1, sj = -1, di = -1, dj = -1;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (matrix[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    if (bfs(si, sj, di, dj))
    {
        markPath(di, dj, si, sj);
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
