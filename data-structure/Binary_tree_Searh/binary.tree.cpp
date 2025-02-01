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

// Function to input a binary tree
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
        Node *f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        if (l != -1)
        {
            Node *leftNode = new Node(l);
            f->left = leftNode;
            q.push(leftNode);
        }
        if (r != -1)
        {
            Node *rightNode = new Node(r);
            f->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

// Function to search for a value in a binary search tree
int search_binary_tree(Node *root, int searchValue)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->val == searchValue)
    {
        return root->val;
    }

    if (root->val > searchValue)
    {
        return search_binary_tree(root->left, searchValue);
    }
    else
    {
        return search_binary_tree(root->right, searchValue);
    }
}

/// insert node in binary tree
void insert_node_in_binary(Node *&root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
    }

    if (root->val > val)
    {
        if (root->left == NULL)
            root->left = new Node(val);
        else
            insert_node_in_binary(root->left, val);
    }
    else
    {
        if (root->right == NULL)
            root->right = new Node(val);
        else
            insert_node_in_binary(root->right, val);
    }
}

// print node value
void binary_tree_print(Node *root)
{
    if (root == NULL)
    {
        return;
    }

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
    int val;
    cin >> val;

    int value = search_binary_tree(root, val);

    if (value != -1)
    {
        cout << "Found: " << value << endl;
    }
    else
    {
        cout << "Value not found" << endl;
    }

    // insert node value in binary tree
    int insert;
    cin >> insert;

    // insert node in binary
    insert_node_in_binary(root, insert);

    // print value
    binary_tree_print(root);

    return 0;
}
