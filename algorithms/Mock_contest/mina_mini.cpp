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

int findMinDifference(vector<int> &coins, int n)
{
    int total_sum = 0;
    for (int coin : coins)
    {
        total_sum += coin;
    }

    int min_diff = 1000000000;
    int subset_count = (1 << n);

    for (int mask = 0; mask < subset_count; mask++)
    {
        int subset_sum = 0, subset_size = 0;
        for (int j = 0; j < n; j++)
        {
            if (mask & (1 << j))
            {
                subset_sum += coins[j];
                subset_size++;
            }
        }
        if (subset_size == n / 2 || subset_size == (n + 1) / 2)
        {
            int diff = abs(total_sum - 2 * subset_sum);
            if (diff < min_diff)
            {
                min_diff = diff;
            }
        }
    }
    return min_diff;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> coins(n);
        for (int i = 0; i < n; i++)
            cin >> coins[i];
        cout << findMinDifference(coins, n) << endl;
    }
    return 0;
}
