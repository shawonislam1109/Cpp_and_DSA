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
vector<int> sizes(100000, 1);

int find(int val, vector<int> &leaders)
{
    if (leaders[val] == -1)
        return val;
    int leader = find(leaders[val], leaders);
    leaders[val] = leader;
    return leader;
}

void group_union(int a, int b, vector<int> &leaders)
{

    int leaderA = find(a, leaders);
    int leaderB = find(b, leaders);
    if (sizes[leaderA] < sizes[leaderB])
    {
        leaders[leaderB] = leaderA;
        sizes[leaderA] += sizes[leaderB];
    }
    else
    {
        leaders[leaderA] = leaderB;
        sizes[leaderB] += sizes[leaderA];
    }
}

int main()
{
    vector<int> leaders(6, -1);
    group_union(0, 1, leaders);
    group_union(1, 2, leaders);
    group_union(3, 4, leaders);
    group_union(4, 5, leaders);
    group_union(2, 5, leaders);

    for (int i = 0; i < leaders.size(); i++)
    {
        cout << i << " :-> " << leaders[i] << " " << endl;
    }
    cout << endl;

    return 0;
}
