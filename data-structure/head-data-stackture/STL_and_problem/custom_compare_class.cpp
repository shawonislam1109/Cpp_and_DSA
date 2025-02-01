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

// students class
class Students
{
public:
    string name;
    int roll;
    int marks;
    Students(string name, int roll, int marks)
    {
        this->name = name;
        this->marks = marks;
        this->roll = roll;
    }
};

// compare class
class cmp
{
public:
    bool operator()(Students l, Students r)
    {
        // return l.marks < r.marks;
        if (l.marks < r.marks)
        {
            return true;
        }
        else if (l.marks > r.marks)
        {
            return false;
        }
        else
        {
            return l.roll > r.roll;
        }
    }
};

// main functions
int main()
{
    priority_queue<Students, vector<Students>, cmp> pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Students obj(name, roll, marks);
        pq.push(obj);
    }

    while (!pq.empty())
    {
        cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}
