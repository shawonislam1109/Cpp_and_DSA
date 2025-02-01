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

Node *inputBinaryTree()
{

    int val;
    cin >> val;
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while ((!q.empty()))
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *left_leaf, *right_leaf;

        if (l != -1)
        {
            left_leaf = new Node(l);
            p->left = left_leaf;
        }
        if (r != -1)
        {
            right_leaf = new Node(val);
            p->right = right_leaf;
        }

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }

    return root;
};

// count node
int countTree(Node *root)
{

    if (root == NULL)
        return 0;

    int l = countTree(root->left);
    int r = countTree(root->right);

    return l + r + 1;
};

// leaf node count
int leaf_node_count(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int l = leaf_node_count(root->left);
    int r = leaf_node_count(root->right);

    return l + r;
}

// get maximum height
int maximumHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = maximumHeight(root->left);
    int r = maximumHeight(root->right);

    return max(l, r) + 1;
};

int main()
{
    // cout << "hello world";
    Node *root = inputBinaryTree();

    int count = countTree(root);
    int leaf = leaf_node_count(root);

    cout << count;

    cout << endl;

    cout << leaf << endl;

    cout << "max hight" << endl;

    cout << maximumHeight(root) << endl;
    return 0;
}
