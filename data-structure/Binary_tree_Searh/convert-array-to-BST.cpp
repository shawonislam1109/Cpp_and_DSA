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
    int rootValue;
    cin >> rootValue;

    if (rootValue == -1)
    {
        return NULL;
    }

    Node *root = new Node(rootValue);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        int l, r;
        if (l != -1)
        {
            Node *leftNode = new Node(l);
            f->left = leftNode;
            q.push(f->left);
        }
        if (r != -1)
        {
            Node *rightNode = new Node(l);
            f->right = rightNode;
            q.push(f->right);
        }
    }
};

// convert array to bst
Node *convert_array_to_bst(int v[], int l, int r)
{
    if (l > r)
        return NULL;

    int mid = (l + r) / 2;

    Node *root = new Node(v[mid]);

    Node *leftRoot = convert_array_to_bst(v, l, mid - 1);
    Node *rightRoot = convert_array_to_bst(v, mid + 1, r);

    root->left = leftRoot;
    root->right = rightRoot;

    return root;
}

// print Node
void print(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Node *root = convert_array_to_bst(a, 0, n);
    print(root);

    return 0;
}
