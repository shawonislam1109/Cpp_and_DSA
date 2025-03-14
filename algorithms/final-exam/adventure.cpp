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

int dp[1005][1005];

int knapsack(int n, int max_weight, vector<int> &weights, vector<int> &values)
{

    if (n < 0 || max_weight < 0)
        return 0;

    if (dp[n][max_weight] != -1)
        return dp[n][max_weight];

    if (max_weight >= weights[n - 1])
    {
        dp[n][max_weight] = max(knapsack(n - 1, max_weight - weights[n - 1], weights, values) + values[n - 1], knapsack(n - 1, max_weight, weights, values));
    }
    else
    {
        dp[n][max_weight] = knapsack(n - 1, max_weight, weights, values);
    }

    return dp[n][max_weight];
};

int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        int n, w;
        cin >> n >> w;
        vector<int> weights(n);
        vector<int> values(n);

        for (int i = 0; i < n; i++)
        {
            cin >> weights[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> values[i];
        }

        memset(dp, -1, sizeof(dp));

        cout << knapsack(n, w, weights, values) << endl;
    }

    return 0;
}
