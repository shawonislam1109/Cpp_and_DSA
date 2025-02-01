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
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Input tree
Node *inputTree()
{
    int val;
    cin >> val;
    if (val == -1)
    {
        return NULL;
    }

    Node *root = new Node(val);
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> frontNode = q.front();
        Node *parent = frontNode.first;
        q.pop();

        int l, r;

        cin >> l >> r;

        if (l != -1)
        {
            Node *left = new Node(l);
            parent->left = left;
            q.push({left, frontNode.second + 1});
        }
        if (r != -1)
        {
            Node *right = new Node(r);
            parent->right = right;
            q.push({right, frontNode.second + 1});
        }
    }

    return root;
}

// Print nodes at a specific level
void printLevel(Node *root, int level)
{
    if (!root)
        return;

    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> frontNode = q.front();
        Node *current = frontNode.first;
        int currentLevel = frontNode.second;
        q.pop();

        if (currentLevel == level)
        {
            cout << current->val << " ";
        }

        if (current->left)
        {
            q.push({current->left, currentLevel + 1});
        }
        if (current->right)
        {
            q.push({current->right, currentLevel + 1});
        }
    }
    pair<Node *, int> lastNode = q.front();
    int lastLevel = lastNode.second;
    if (lastLevel < level)
    {
        cout << "Invalid" << endl;
    }
}

int main()
{
    Node *root = inputTree();

    int level;
    cin >> level;

    printLevel(root, level);

    return 0;
}
