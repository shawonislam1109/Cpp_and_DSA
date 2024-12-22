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

// Node linked list
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

// print backword
void printBackword(Node *tail)
{

    Node *tempTail = tail;

    while (tail != NULL)
    {
        cout << tail->val << endl;
        tail = tail->prev;
    }
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

    cout << "Print Forword" << endl;

    // print forword
    printForword(head);

    cout << "Print Backword" << endl;
    // print backword
    printBackword(tail);

    // cout << "hello world";
    return 0;
}
