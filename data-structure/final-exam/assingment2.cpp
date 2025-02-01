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

class Person
{
public:
    string s;
    int i;
    Person(string s, int i)
    {
        this->i = i;
        this->s = s;
    }
};

class Cmp
{
public:
    bool operator()(Person l, Person r)
    {
        if (l.s > r.s)
        {
            return true;
        }
        else if (l.s < r.s)
        {
            return false;
        }
        else
        {
            return l.i > r.i;
        }
    }
};

int main()
{
    priority_queue<Person, vector<Person>, Cmp> pq;

    int query;
    cin >> query;

    while (query--)
    {
        string name;
        int x;
        cin >> name >> x;
        Person obj(name, x);
        pq.push(obj);
    }

    while (!pq.empty())
    {
        cout << pq.top().s << " " << pq.top().i << endl;
        pq.pop();
    }

    return 0;
}
