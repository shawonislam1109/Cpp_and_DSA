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

// insert in tail linked list
void insert_linked_tail(Node *&head, Node *&tail, int val)
{

    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    tail->next = newNode;
    tail = newNode;
};

// print linked ist
void linked_list_print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "Node value is " << temp->val << endl;
        temp = temp->next;
    }
};

int main()
{
    int N;
    cin >> N;
    Node *head = NULL;
    Node *tail = head;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        insert_linked_tail(head, tail, x);
    }

    linked_list_print(head);
    return 0;
}
