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
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void reverse(ListNode *&head, ListNode *temp)
{
    if (temp->next == NULL)
    {
        head = temp;
        return;
    }
    reverse(head, temp->next);
    temp->next->next = temp;
    temp->next = NULL;
}

void delete_at_any(ListNode *&head, int n)
{
    ListNode *temp = head;

    if (temp->next == NULL)
    {
        head = NULL;
        delete temp;
        return;
    }
    if (n == 1)
    {
        head = temp->next;
        return;
    }

    for (int i = 1; i + 1 < n; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
};

void insert_node(ListNode *&head, ListNode *&tail, int val)
{
    ListNode *newNode = new ListNode(val);
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
    ListNode *head = NULL;
    ListNode *tail = NULL;

    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insert_node(head, tail, x);
    }

    ListNode *temp = head;
    // reverse(temp, temp);

    // delete_at_any(temp, 2);

    // reverse(temp, temp);

    ListNode *dummy = new ListNode(0, head);

    while (dummy != NULL)
    {
        cout << dummy->val << endl;
        dummy = dummy->next;
    }

    return 0;
}
