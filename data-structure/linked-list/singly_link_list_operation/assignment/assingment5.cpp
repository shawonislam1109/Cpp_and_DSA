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

// Insert at the tail of the linked list
void linked_list_insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

// Remove duplicates from the linked list
void remove_duplicates(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *runner = current;
        while (runner->next != NULL)
        {
            if (runner->next->val == current->val)
            {
                Node *toDelete = runner->next;
                runner->next = runner->next->next;
                delete toDelete;
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// Print the linked list
void linked_list_output(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int value;
    while (cin >> value && value != -1)
    {
        linked_list_insert_tail(head, tail, value);
    }

    remove_duplicates(head);

    linked_list_output(head);

    return 0;
}