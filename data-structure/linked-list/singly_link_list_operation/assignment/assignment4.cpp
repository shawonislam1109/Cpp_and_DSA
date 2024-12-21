#include <iostream>
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

// Insert at the head of the linked list
void linked_list_insert_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
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
};

// Delete at the V-th index
void linked_list_delete(Node *&head, Node *&tail, int index)
{
    if (head == NULL || index < 0)
        return;
    if (index == 0)
    {
        Node *toDelete = head;
        head = head->next;
        if (head == NULL)
            tail = NULL;
        delete toDelete;
        return;
    }
    Node *temp = head;
    for (int i = 0; i < index - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
        return;
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete == tail)
        tail = temp;
    delete toDelete;
};

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
};

int main()
{
    int Q;
    cin >> Q;

    Node *head = NULL;
    Node *tail = NULL;

    while (Q--)
    {
        int X, V;
        cin >> X >> V;
        if (X == 0)
        {
            linked_list_insert_head(head, tail, V);
        }
        else if (X == 1)
        {
            linked_list_insert_tail(head, tail, V);
        }
        else if (X == 2)
        {
            linked_list_delete(head, tail, V);
        }
        linked_list_output(head);
    }

    return 0;
}
