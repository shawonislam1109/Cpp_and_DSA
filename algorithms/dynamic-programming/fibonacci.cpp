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

vector<int> dp(10005, -1);

int fibonacci(int s)
{
    if (s < 2)
        return 1;
    if (dp[s] != -1)
        return dp[s];
    return dp[s] = fibonacci(s - 1) + fibonacci(s - 2);
}

int main()
{
    cout << fibonacci(5);
    return 0;
}
