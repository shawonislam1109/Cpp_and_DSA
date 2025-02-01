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

// input tree
Node *inputTree()
{

    int val;
    cin >> val;
    if (val == -1)
    {
        return NULL;
    };

    int maximum = 0;
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            Node *leftNewNode = new Node(l);
            f->left = leftNewNode;
        }
        if (r != -1)
        {
            Node *rightNode = new Node(r);
            f->right = rightNode;
        }

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }

    return root;
};

// total node of tree count
int treeCount(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = treeCount(root->left);
    int r = treeCount(root->right);

    return l + r + 1;
}

int max_height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int l = max_height(root->left);
    int r = max_height(root->right);

    return max(l, r) + 1;
}

int main()
{
    Node *root = inputTree();

    int allTree = treeCount(root);
    int max_heigh = max_height(root);

    int real_tree = pow(2, max_heigh) - 1;

    if (real_tree == allTree)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}