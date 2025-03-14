#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // for memset

using namespace std;

vector<int> vertices[1005];
int vis[1005];
int level[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (int x : vertices[f])
        {
            if (!vis[x])
            {
                q.push(x);
                vis[x] = true;
                level[x] = level[f] + 1;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int x, y;
        cin >> x >> y;

        vertices[x].push_back(y);
        vertices[y].push_back(x);
    }

    int d, s;
    cin >> d >> s;

    memset(vis, 0, sizeof(vis));
    memset(level, -1, sizeof(level));

    bfs(s);

    for (int i = 0; i < n; i++)
    {
        cout << i << " :-> " << level[i] << endl;
    }

    return 0;
}
