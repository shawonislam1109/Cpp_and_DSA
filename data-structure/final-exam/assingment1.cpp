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
    set<int> mySet;

    int query;
    cin >> query;

    while (query--)
    {
        int arraySize;
        cin >> arraySize;
        for (int i = 0; i < arraySize; i++)
        {
            int v;
            cin >> v;
            mySet.insert(v);
        }
        for (set<int>::iterator it = mySet.begin(); it != mySet.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
        mySet.clear();
    }

    return 0;
}
