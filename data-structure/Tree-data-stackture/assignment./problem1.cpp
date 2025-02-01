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

int maximum = 0;

// sum function with leaf node
void sumFunc(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left != NULL || root->right != NULL)
    {
        maximum = +root->val;
    }

    sumFunc(root->left);
    sumFunc(root->right);
}

int main()
{
    Node *root = inputTree();

    sumFunc(root);
    cout << maximum << endl;

    return 0;
}
