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

class MyStack
{
public:
    vector<int> v;

    void push(int n)
    {
        v.push_back(n);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v.back();
    }

    bool empty()
    {
        return v.empty();
    }
    int size()
    {
        return v.size();
    }
};

int main()
{
    int x, t, y, u;
    cin >> x >> t >> y >> u;

    MyStack *mycla = new MyStack();
    mycla->push(x);
    mycla->push(t);
    mycla->push(y);
    mycla->push(u);

    for (vector<int>::iterator it = mycla->v.begin(); it != mycla->v.end(); ++it)
    {
        cout << *it << endl;
    }
}
