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
    stack<int> st;
    queue<int> qu;

    int n, m;
    cin >> n >> m;

    while (n--)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    while (m--)
    {
        int x;
        cin >> x;
        qu.push(x);
    }

    // Check if sizes are different
    if (st.size() != qu.size())
    {
        cout << "NO" << endl;
        return 0;
    }

    // Compare stack and queue elements
    while (!st.empty() && !qu.empty())
    {
        if (st.top() != qu.front())
        {
            cout << "NO" << endl;
            return 0;
        }
        st.pop();
        qu.pop();
    }

    cout << "YES" << endl;
    return 0;
}
