#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string val;
    Node *next;
    Node *prev;
    Node(string val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a node into the doubly linked list
void insert_node(Node *&head, Node *&tail, string val)
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
        newNode->prev = tail;
        tail = newNode;
    }
}

// Function to print the current node's value
void print_current(Node *current)
{
    if (current)
    {
        cout << current->val << endl;
    }
    else
    {
        cout << "Not Available" << endl;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *current = NULL;

    string x;
    while (true)
    {
        cin >> x;
        if (x == "end")
        {
            break;
        }
        insert_node(head, tail, x);
    }

    // Process commands
    int T;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        string command;
        cin >> command;

        if (command == "visit")
        {
            string site;
            cin >> site;

            Node *temp = head;
            bool found = false;
            while (temp != NULL)
            {
                if (temp->val == site)
                {
                    current = temp;
                    print_current(current);
                    found = true;
                    break;
                }
                temp = temp->next;
            }
            if (!found)
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "next")
        {
            if (current != NULL && current->next != NULL)
            {
                current = current->next;
                print_current(current);
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "prev")
        {
            if (current != NULL && current->prev != NULL)
            {
                current = current->prev;
                print_current(current);
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}
