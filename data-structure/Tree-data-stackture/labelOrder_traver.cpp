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
};

// level order printing
void levelOderPrint(Node *root)
{

    if (root == NULL)
    {
        cout << "No Tree" << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // keep then node
        Node *f = q.front();
        // previous node pop
        q.pop();

        // value print
        cout << f->val << " ";

        // push left and right
        if (f->left_leaf)
            q.push(f->left_leaf);
        if (f->right_leaf)
            q.push(f->right_leaf);
    }
};

int main()
{
    // node create and connection
    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);
    Node *f = new Node(70);

    // node dereferening
    root->left_leaf = a;
    root->right_leaf = b;
    a->left_leaf = c;
    a->right_leaf = d;
    c->left_leaf = e;
    c->right_leaf = f;

    // print queue
    levelOderPrint(root);

    return 0;
}
