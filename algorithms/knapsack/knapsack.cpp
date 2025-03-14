#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int weights[1005], value[1005];
int dp[1005][1005];

int knapsack(int n, int weight)
{

    if (n == 0 || weight == 0)
        return 0;

    if (dp[n][weight] != -1)
        return dp[n][weight];

    if (weights[n - 1] <= weight)
    {
        int take = knapsack(n - 1, weight - weights[n - 1]) + value[n - 1];
        int skip = knapsack(n - 1, weight);
        dp[n][weight] = max(take, skip);
    }
    else
    {
        dp[n][weight] = knapsack(n - 1, weight);
    }

    return dp[n][weight];
}

int main()
{
    int n, weight;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    cin >> weight;

    memset(dp, -1, sizeof(dp));

    cout << knapsack(n, weight) << endl;

    return 0;
}
