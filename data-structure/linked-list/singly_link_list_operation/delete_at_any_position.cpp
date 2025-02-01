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

// Insert at tail in the linked list
void insert_linked_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Print linked list in reverse
void linked_list_print_reverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << "Node value in reverse: " << head->val << endl;
    linked_list_print_reverse(head->next); // Process next node first
}

// Delete node at any position in the linked list
void delete_any_position(Node *&head, int index)
{
    if (index < 1 || head == NULL)
    {
        cout << "Invalid index or empty list!" << endl;
        return;
    }

    if (index == 1)
    {
        // Delete head
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < index - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Index out of bounds!" << endl;
        return;
    }

    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}

int main()
{
    int N;
    cin >> N;
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insert_linked_tail(head, tail, x);
    }

    delete_any_position(head, 2); // Delete the second node

    linked_list_print_reverse(head); // Print list in reverse order
    return 0;
}
