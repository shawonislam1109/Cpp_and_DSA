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

vector<int> dp;

int tetranacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    if (n == 3)
        return 2;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = tetranacci(n - 1) + tetranacci(n - 2) + tetranacci(n - 3) + tetranacci(n - 4);
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    dp.resize(n + 1, -1);
    cout << tetranacci(n) << endl;
    return 0;
}
