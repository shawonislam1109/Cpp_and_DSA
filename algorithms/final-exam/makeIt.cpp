#include <iostream>
#include <map>

using namespace std;

int dp[10005];

bool makeIt(int n, int target)
{
    if (target < n)
        return false;

    if (n == target)
        return true;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = makeIt(n + 3, target) || makeIt(n * 2, target);
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        memset(dp, -1, sizeof(dp));
        if (makeIt(1, x))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
