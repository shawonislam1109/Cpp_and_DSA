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
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

// print forword
void printForword(Node *head)
{
    // Doubly linked list print
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
};

// insert at head
void insert_at_head(Node *&head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    newNode->next = temp;
    head = newNode;
};

// insert at tail
void insert_at_tail(Node *&tail, int val)
{
    Node *newNode = new Node(val);
    Node *temp = tail;
    tail->next = newNode;
    newNode->prev = temp;
    tail = newNode;
};

// insert at any position
void insert_at_any_position(Node *&head, Node *&tail, int val, int index)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }

    Node *temp = head;
    Node *temp2 = tail;

    for (int i = 0; i <= index; i++)
    {
        temp = temp->next;
    }

    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
};

// doubly linked is deleted at head
void deleted_at_head(Node *&head, Node *&tail)
{

    Node *temp = head;
    head = temp->next;
    delete temp;
    if (head == NULL)
    {
        tail = NULL;
        return;
    }
    head->prev = NULL;
};

//  doubly linked list delete at tail
void deleted_at_tail(Node *&tail, Node *&head)
{
    Node *temp = tail;
    tail = temp->prev;
    delete temp;

    if (tail == NULL)
    {
        head = NULL;
    }
    tail->next = NULL;
};

// delete at any position
void delete_at_any_position(Node *&head, int index)
{

    Node *temp = head;

    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
};
int main()
{

    Node *head = new Node(30);
    Node *a = new Node(50);
    Node *b = new Node(10);
    Node *tail = new Node(70);

    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = tail;
    tail->prev = b;

    // insert at head
    insert_at_head(head, 900);

    // insert at any position
    insert_at_any_position(head, tail, 230, 3);
    insert_at_any_position(head, tail, 780, 1);

    // insert at tail
    insert_at_tail(tail, 500);

    // delete at head
    deleted_at_head(head, tail);

    // delete at tail
    deleted_at_tail(tail, head);

    // delete at any position
    delete_at_any_position(head, 1);

    cout << "Print Forword" << endl;
    // print forword
    printForword(head);

    // cout << "hello world";
    return 0;
}
