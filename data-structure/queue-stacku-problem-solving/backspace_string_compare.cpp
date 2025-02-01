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
    string s = "ab#c";
    string t = "ad#c";

    stack<char> st;
    stack<char> st2;

    for (char get1 : s)
    {

        if (get1 == '#' && !st.empty())
        {
            st.pop();
        }
        else
        {
            st.push(get1);
        }
    }
    for (char get1 : t)
    {

        if (get1 == '#' && !st.empty())
        {
            st2.pop();
        }
        else
        {
            st2.push(get1);
        }
    }

    if (st.size() != st2.size())
    {
        cout << false;
    }

    while (!st.empty() || !st2.empty())
    {
        if (st.top() != st2.top())
        {
            cout << false;
        }
        st.pop();
        st2.pop();
    }

    cout << true;

    return 0;
}
