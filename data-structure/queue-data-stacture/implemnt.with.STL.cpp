
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

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MyQueue
{
public:
    list<int> l;

    void push(int val)
    {
        l.push_back(val);
    }

    void pop()
    {
        l.pop_front();
    }

    int front()
    {
        return l.front();
    }

    int back()
    {
        return l.back();
    }

    bool empty()
    {
        return l.empty();
    }

    int size()
    {
        return l.size();
    }

    // print queue
    void print_queue()
    {
        for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main()
{
    MyQueue ticket;

    ticket.push(20);
    ticket.push(10);
    ticket.push(40);
    ticket.push(50);

    cout << "Queue contents:" << endl;
    ticket.print_queue();

    cout << "Front: " << ticket.front() << endl;
    cout << "Back: " << ticket.back() << endl;

    ticket.pop();
    cout << "After one pop:" << endl;
    ticket.print_queue();

    cout << "Queue size: " << ticket.size() << endl;
    cout << "Is queue empty? " << (ticket.empty() ? "Yes" : "No") << endl;

    return 0;
}
