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
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

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
        this->next = NULL;
    }
};

//  insert node
void insert_node(Node *&head, Node *&tail, int val)

{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int main()
{
    list<int> l;
    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }
        l.push_back(x);
    }

    l.sort();
    l.unique();

    for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    return 0;
}
