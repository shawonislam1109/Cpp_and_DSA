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

int main()
{

    // pair<int, string> p;
    // p = make_pair(3, "shawon");
    // p = {3, "HI"};

    // cout << p.first << " " << p.second;

    int x;
    cin >> x;
    vector<pair<int, int>> v(x);

    // To add elements, use push_back or resize the vector
    v.push_back(make_pair(3, 4));

    for (int i = 0; i < x; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < x; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}
