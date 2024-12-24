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
    list<int> l(5, 0);
    // l = {34, 4, 52, 3};
    // l.assign({45, 234, 23, 39});
    // for (auto it = l.begin(); it != l.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    list<int> l2;
    // l2.assign(l.begin(), l.end());
    l2 = l;

    l2.push_back(394);
    l2.push_front(304);

    // l2.pop_back();
    // l2.pop_front();

    // cout << *next(l2.begin(), 1) << endl;

    l2.insert(next(l2.begin(), 4), 450);

    // range base for loop

    for (int val : l2)
    {
        cout << val << endl;
    }

    return 0;
}
