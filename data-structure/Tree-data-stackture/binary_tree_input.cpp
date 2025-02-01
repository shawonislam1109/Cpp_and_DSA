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

// input binary tree
Node *inputTree()
{
    int val;
    cin >> val;
    if (val == -1)
    {
        return NULL;
    }
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // keep value queue front value
        Node *p = q.front();
        q.pop();

        // value assign in left and right
        int l, r;
        cin >> l >> r;
        Node *left_leaf, *rightLeaf;
        if (l != -1)
        {
            left_leaf = new Node(l);
            p->left = left_leaf;
        }
        else
        {
            p->left = NULL;
        }

        if (r != -1)
        {
            rightLeaf = new Node(r);
            p->right = rightLeaf;
        }
        else
        {
            p->right = NULL;
        }

        // queue push
        if (p->left)
            q.push(left_leaf);
        if (p->right)
            q.push(rightLeaf);
    }

    return root;
}

// Node *inputTree()
// {
//     int val;
//     cin >> val;
//     if (val == -1) // Edge case: root itself is null
//         return NULL;

//     Node *root = new Node(val);
//     queue<Node *> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         // Keep the queue front value
//         Node *p = q.front();
//         q.pop();

//         // Input values for left and right children
//         int l, r;
//         cin >> l >> r;

//         if (l != -1) // Only create left child if l != -1
//         {
//             Node *left_leaf = new Node(l);
//             p->left = left_leaf;
//             q.push(left_leaf); // Add to queue
//         }
//         else
//         {
//             p->left = NULL;
//         }

//         if (r != -1) // Only create right child if r != -1
//         {
//             Node *rightLeaf = new Node(r);
//             p->right = rightLeaf;
//             q.push(rightLeaf); // Add to queue
//         }
//         else
//         {
//             p->right = NULL;
//         }
//     }

//     return root;
// }

// print level order
void print_level_order(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

int main()
{

    Node *root = inputTree();
    ;

    // print node
    print_level_order(root);

    return 0;
}
