// // stdc++.h
// #include <iostream>
// #include <vector>
// #include <string>
// #include <map>
// #include <set>
// #include <algorithm>
// #include <queue>
// #include <stack>
// #include <cmath>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <climits>
// #include <functional>
// #include <utility>
// #include <iomanip>
// #include <fstream>
// #include <list>
// // Add other commonly used headers as needed
// using namespace std;

// vector<vector<char>> graph;
// vector<vector<int>> visited;
// vector<vector<pair<int, int>>> parent;
// vector<vector<int>> level;
// vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// int n, m;
// int si, sj, di, dj;

// bool isValid(int i, int j)
// {
//     return i >= 0 && i < n && j >= 0 && j < m && graph[i][j] == '.' || graph[i][j] == 'A' || graph[i][j] == 'B';
// }

// void bfs(int i, int j)
// {
//     queue<pair<int, int>> q;
//     q.push({i, j});
//     visited[i][j] = 1;
//     level[i][j] = 0;
//     while (!q.empty())
//     {
//         auto p = q.front();
//         q.pop();
//         for (auto [dx, dy] : dir)
//         {
//             int ci = dx + p.first;
//             int cj = dy + p.second;

//             if (isValid(ci, cj) && !visited[ci][cj])
//             {
//                 visited[ci][cj] = 1;
//                 q.push({ci, cj});
//                 parent[ci][cj] = {p.first, p.second};
//                 level[ci][cj] = level[p.first][p.second] + 1;
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     graph.resize(n, vector<char>(m, '.'));
//     visited.resize(n, vector<int>(m, 0));
//     parent.resize(n, vector<pair<int, int>>(m, {-1, -1}));
//     level.resize(n, vector<int>(m, -1));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> graph[i][j];

//             if (graph[i][j] == 'A')
//             {
//                 si = i;
//                 sj = j;
//             }
//             if (graph[i][j] == 'B')
//             {
//                 di = i;
//                 dj = j;
//             }
//         }
//     }

//     bfs(si, sj);

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cout << graph[i][j] << " ";
//         }
//         cout << endl;
//     }

//     cout << endl;

//     if (level[di][dj] != -1)
//     {
//         cout << "YES" << " level :-> " << level[di][dj] << endl;

//         vector<pair<int, int>> path;
//         pair<int, int> p = {di, dj};

//         while (p.first != si || p.second != sj)
//         {
//             path.push_back(p);
//             p = parent[p.first][p.second];
//         }
//         // path.push_back({si, sj});
//         reverse(path.begin(), path.end());

//         cout << "path :";
//         for (auto [x, y] : path)
//         {
//             cout << "(" << x << ',' << y << ")" << " ";
//         }
//         cout << endl;
//     }
//     else
//     {
//         cout << "NO" << " level :-> " << level[di][dj] << endl;
//     }

//     return 0;
// }

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
using namespace std;

vector<vector<char>> graph;
vector<vector<int>> visited;
vector<vector<pair<int, int>>> parent;
vector<vector<int>> level;
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int r, c;
int si, sj, di, dj;

bool isValid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c && graph[i][j] == '.' || graph[i][j] == 'A' || graph[i][j] == 'B';
}

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;
    level[i][j] = 0;

    while (!q.empty())
    {
        auto [par_i, par_j] = q.front();
        q.pop();

        for (auto [dx, dy] : dir)
        {
            int ci = dx + par_i;
            int cj = dy + par_j;
            if (isValid(ci, cj) && !visited[ci][cj])
            {
                visited[ci][cj] = 1;
                q.push({ci, cj});
                parent[ci][cj] = {par_i, par_j};
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    cin >> r >> c;

    graph.resize(r, vector<char>(c, '.'));
    visited.resize(r, vector<int>(c, 0));
    parent.resize(r, vector<pair<int, int>>(c, {-1, -1}));
    level.resize(r, vector<int>(c, -1));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (graph[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    bfs(si, sj);

    if (level[di][dj] != -1)
    {
        cout << "level Count : " << level[di][dj] << endl;

        vector<pair<int, int>> path;
        vector<char> side;
        pair<int, int> p = {di, dj};
        while (p.first != si || p.second != sj)
        {
            path.push_back(p);
            p = parent[p.first][p.second];
        }
        // path.push_back({si, sj});
        reverse(path.begin(), path.end());

        cout << "path : ";
        for (auto [x, y] : path)
        {
            
            cout << "(" << x << ',' << y << ")" << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << " level :-> " << level[di][dj] << endl;
    }
    return 0;
}
