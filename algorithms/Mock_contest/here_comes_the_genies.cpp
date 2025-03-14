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

long long int max_balls(long long int n, vector<long long int> &arr)
{
    sort(arr.begin(), arr.end());
    long long int last_taken = arr[n - 1] + 1, total_balls = 0;

    for (long long int i = n - 1; i >= 0; i--)
    {
        last_taken = max(0LL, min(arr[i], last_taken - 1));
        total_balls += last_taken;
    }

    return total_balls;
}

int main()
{
    long long int n;
    cin >> n;

    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << max_balls(n, arr) << endl;

    return 0;
}
