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
// Add other commonly used headers as needed
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void print_linked_output(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << 0 << endl;
        return;
    }

    Node *max = head;
    Node *min = head;

    Node *current = head;

    while (current != NULL)
    {
        if (max->val < current->val)
        {
            max = current;
        }
        if (min->val > current->val)
        {
            min = current;
        }
        current = current->next;
    }

    cout << max->val - min->val << endl;
}

void input_linked_list(Node *&head, Node *&tail, int val)
{
    Node *new_node = new Node(val);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
};

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }
        input_linked_list(head, tail, x);
    }

    print_linked_output(head);
    return 0;
}
