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

// Node class for linked list
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

// insert at head in linked list
void insert_at_head(Node *&head, int val)
{

    Node *new_node = new Node(val);
    new_node->next = head;
    head = new_node;
};

// print linked list
void linked_list_print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
};

// main fuction
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);

    head->next = a;
    a->next = b;

    // insert in head
    insert_at_head(head, 300);
    insert_at_head(head, 500);
    insert_at_head(head, 600);

    // print liked list function
    linked_list_print(head);

    return 0;
}
