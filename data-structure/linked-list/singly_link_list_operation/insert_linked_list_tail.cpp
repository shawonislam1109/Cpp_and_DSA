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

// linked list insert in tail
void insert_linked_list_tail(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
};

// print linked ist
void linked_list_print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
};

int main()
{

    // Node *head = new Node(890);
    // Node *a = new Node(39);

    // head->next = a;

    // insert_linked_list_tail(head, 901);

    Node *head = NULL;

    insert_linked_list_tail(head, 200);
    insert_linked_list_tail(head, 399);

    linked_list_print(head);
    return 0;
}
