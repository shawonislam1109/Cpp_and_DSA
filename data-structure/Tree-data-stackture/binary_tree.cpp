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
    Node *left_leaf;
    Node *right_leaf;
    Node(int val)
    {
        this->val = val;
        this->left_leaf = NULL;
        this->right_leaf = NULL;
    }

    // pre order in tree
    void preOrderPrint(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->val << " ";
        preOrderPrint(root->left_leaf);
        preOrderPrint(root->right_leaf);
    }
    // in order in tree
    void inOrderPrint(Node *root)
    {
        if (root == NULL)
            return;
        inOrderPrint(root->left_leaf);
        cout << root->val << " ";
        inOrderPrint(root->right_leaf);
    }
    // post order in tree
    void postOrder(Node *root)
    {
        if (root == NULL)
            return;
        postOrder(root->left_leaf);
        postOrder(root->right_leaf);
        cout << root->val << " ";
    }
};

// main tree
int main()
{

    // node create and connection
    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);

    // node dereferening
    root->left_leaf = a;
    root->right_leaf = b;
    a->left_leaf = c;
    a->right_leaf = d;
    c->left_leaf = e;

    // print pre order
    root->preOrderPrint(root);

    cout << endl;
    // print in order
    root->inOrderPrint(root);

    cout << endl;

    // print post order
    root->postOrder(root);

    return 0;
}
