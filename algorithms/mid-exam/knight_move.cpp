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

const int MAX_N = 100;
bool vis[MAX_N][MAX_N];
int level[MAX_N][MAX_N];
vector<pair<int, int>> d = {
    {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {2, 1}, {1, 2}, {-1, 2}};
int n, m;

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        auto [par_i, par_j] = q.front();
        q.pop();

        for (auto [dx, dy] : d)
        {
            int ci = par_i + dx;
            int cj = par_j + dy;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        int si, sj, di, dj;
        cin >> si >> sj;
        cin >> di >> dj;

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        bfs(si, sj);

        cout << level[di][dj] << endl;
    }

    return 0;
}
