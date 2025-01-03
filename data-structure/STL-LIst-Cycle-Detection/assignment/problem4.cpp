#include <iostream>
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
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to print the list from left to right and right to left
void printList(Node *head, Node *tail)
{

    cout << "L -> ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "R -> ";
    temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void insertNode(Node *&head, Node *&tail, int x, int v)
{
    Node *newNode = new Node(v);

    if (x < 0)
    {
        cout << "Invalid" << endl;
        return;
    }

    if (x == 0)
    {
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    else
    {
        Node *temp = head;
        int currentIndex = 0;

        while (temp != NULL && currentIndex < x - 1)
        {
            temp = temp->next;
            currentIndex++;
        }

        if (temp == NULL)
        {
            cout << "Invalid" << endl;
            return;
        }

        if (temp->next == NULL)
        {
            temp->next = newNode;
            newNode->prev = temp;
            tail = newNode;
        }
        else
        {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    printList(head, tail);
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int q;
    cin >> q;

    while (q--)
    {
        int X, V;
        cin >> X >> V;
        insertNode(head, tail, X, V);
    }

    return 0;
}
