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

// reverse the linked list
void reverse_singly_linked_list(Node *&head, Node *temp, Node *&tail)
{
    // Node *temp = head;

    if (temp->next == NULL)
    {
        head = temp;
        return;
    }
    reverse_singly_linked_list(head, temp->next, tail);
    temp->next->next = temp;
    temp->next = NULL;
    tail = temp;
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

int main()
{
    Node *head = new Node(50);
    Node *a = new Node(40);
    Node *b = new Node(30);
    Node *c = new Node(20);
    Node *tail = new Node(10);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = tail;

    // reverse linked list
    reverse_singly_linked_list(head, head, tail);

    // print liked list
    linked_list_print(head);

    cout << tail->val << "tail value " << endl;

    return 0;
}
