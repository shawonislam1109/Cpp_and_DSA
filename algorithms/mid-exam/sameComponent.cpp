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
vector<vector<char>> matrix;
vector<vector<int>> visited;
vector<vector<int>> level;
vector<pair<int, int>> movement = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int r, c;
bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
};

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    while (!q.empty())
    {
        auto [px, py] = q.front();
        q.pop();

        for (auto [dx, dy] : movement)
        {
            int ci = px + dx;
            int cj = py + dy;

            if (valid(ci, cj) && !visited[ci][cj] && matrix[ci][cj] == '.')
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[px][py] + 1;
            }
        }
    }
}

int main()
{

    cin >> r >> c;

    // resizing
    matrix.resize(r, vector<char>(c));
    visited.resize(r, vector<int>(c, 0));
    level.resize(r, vector<int>(c, -1));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    bfs(si, sj);

    if (level[di][dj] != -1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
