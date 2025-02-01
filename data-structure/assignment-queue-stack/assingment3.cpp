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
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        stack<char> stk;

        for (char c : s)
        {
            if (!stk.empty() && ((stk.top() == '0' && c == '1') || (stk.top() == '1' && c == '0')))
            {
                stk.pop();
            }
            else
            {
                stk.push(c); 
            }
        }

        if (stk.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}