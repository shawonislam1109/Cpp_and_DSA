#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
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
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *buildTree()
{
    int val;
    cin >> val;
    if (val == -1)
        return nullptr;

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal >> rightVal;

        if (leftVal != -1)
        {
            current->left = new Node(leftVal);
            q.push(current->left);
        }
        if (rightVal != -1)
        {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

void collectLeafNodes(Node *root, map<int, int> &freqMap)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        freqMap[root->val]++;
        return;
    }

    collectLeafNodes(root->left, freqMap);
    collectLeafNodes(root->right, freqMap);
}

int findMostFrequentLeaf(map<int, int> &freqMap)
{
    int maxFreq = 0;
    int result = 101;
    for (const auto &entry : freqMap)
    {
        if (entry.second > maxFreq || (entry.second == maxFreq && entry.first < result))
        {
            maxFreq = entry.second;
            result = entry.first;
        }
    }

    return result;
}

int main()
{
    Node *root = buildTree();

    map<int, int> freqMap;
    collectLeafNodes(root, freqMap);

    int mostFrequentLeaf = findMostFrequentLeaf(freqMap);
    cout << mostFrequentLeaf << endl;

    return 0;
}
