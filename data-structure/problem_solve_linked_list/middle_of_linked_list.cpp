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
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

// print linked

void print_linked_list(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
};

// Node Middle linked find out
Node middle_linked_list_find(Node *head)
{
    Node *temp = head;
    Node *temp2 = head;
    int middle_size = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        middle_size++;
    };

    for (int i = 0; i < middle_size / 2; i++)
    {
        temp2 = temp2->next;
    }

    return *temp2;
};

int main()
{
    Node *head = new Node(1);
    Node *a = new Node(1);
    Node *b = new Node(2);
    // Node *c = new Node(2);
    // Node *e = new Node(3);

    head->next = a;
    a->next = b;
    // b->next = c;
    // c->next = e;

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->val == temp->next->val)
        {
            Node *duplicate = temp->next;
            temp->next = temp->next->next;
            delete duplicate;
        }
        else
        {
            temp = temp->next;
        }
    }

    print_linked_list(head);
    return 0;
}
