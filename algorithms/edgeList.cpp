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
    int N, edge;
    cin >> N >> edge;

    vector<pair<int, int>> edgeList;

    while (edge--)
    {
        int x, y;
        cin >> x >> y;
        edgeList.push_back({x, y});
    }

    for (int i = 0; i < edgeList.size(); i++)
    {
        pair<int, int> getValue = edgeList[i];

        cout << "node " << i << " : " << getValue.first << " " << getValue.second << endl;
    }

    return 0;
}
