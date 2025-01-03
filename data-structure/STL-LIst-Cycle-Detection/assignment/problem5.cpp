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
    int Q;
    cin >> Q;

    list<int> linkedList;

    while (Q--)
    {
        int X, V;
        cin >> X >> V;
        if (X == 0)
        {

            linkedList.push_front(V);
        }
        else if (X == 1)
        {
            linkedList.push_back(V);
        }
        else if (X == 2)
        {
            auto it = linkedList.begin();
            advance(it, V);
            linkedList.erase(it);
        }

        cout << "L -> ";
        for (auto it = linkedList.begin(); it != linkedList.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
        cout << "R -> ";
        for (auto it = linkedList.rbegin(); it != linkedList.rend(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}
