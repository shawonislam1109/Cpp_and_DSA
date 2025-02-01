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
    string s = "()[]{}";

    stack<char> values;
    bool isValid = false;

    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            values.push(ch);
        }
        else
        {
            if (values.empty())
            {
                return false;
            }
            char top = values.top();
            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{'))
            {
                values.pop();
            }
            else
            {
                return false;
            }
        }
    }

    cout << values.empty();

    return 0;
}
