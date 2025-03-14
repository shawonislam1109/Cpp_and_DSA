#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

vector<vector<char>> matrix;
vector<vector<bool>> visited;
vector<pair<int, int>> movement = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int r, c;

bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

int bfs(int si, int sj)
{
    stack<pair<int, int>> s;
    s.push({si, sj});
    visited[si][sj] = true;

    int count = 0;

    while (!s.empty())
    {
        auto [x, y] = s.top();
        s.pop();
        count++;

        for (auto [dx, dy] : movement)
        {
            int ci = x + dx;
            int cj = y + dy;

            if (valid(ci, cj) && !visited[ci][cj] && matrix[ci][cj] == '.')
            {
                visited[ci][cj] = true;
                s.push({ci, cj});
            }
        }
    }
    return count;
}

int main()
{
    cin >> r >> c;

    matrix.resize(r, vector<char>(c));
    visited.resize(r, vector<bool>(c, false));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int minCount = INT_MAX;
    bool hasComponent = false;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!visited[i][j] && matrix[i][j] == '.')
            {
                int getNode = bfs(i, j);
                minCount = min(minCount, getNode);
                hasComponent = true;
            }
        }
    }

    cout << (hasComponent ? minCount : -1) << endl;
    return 0;
}
