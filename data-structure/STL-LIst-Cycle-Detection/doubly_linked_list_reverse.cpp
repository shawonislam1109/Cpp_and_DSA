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
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// reverse the linked list
void reverse_Doubly_linked_list(Node *head, Node *tail)
{

    for (Node *i = head, *j = tail; i != j && i->prev != j; i = head->next, j = tail->prev)
    {
        swap(i->val, j->val);
    }
};

// void liked list pring
void linked_list_print(Node *head)
{
    Node *temp = head;

    if (temp == NULL)
    {
        return;
    }
    cout << temp->val << endl;
    temp = temp->next;
    linked_list_print(temp);
}

// insert output
void insert_out_put(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    tail->next = newNode;
    tail = newNode;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        int n;
        cin >> n;
        if (n == -1)
        {
            break;
        }
        insert_out_put(head, tail, n);
    }
    reverse_Doubly_linked_list(head, tail);

    linked_list_print(head);
    return 0;
}
