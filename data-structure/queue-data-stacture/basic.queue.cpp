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

class MyQueue
{
public:
    Node *head; // Declaration without default initializer
    Node *tail;

    // Constructor to initialize head and tail
    MyQueue()
    {
        head = NULL;
        tail = NULL;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode; // Use tail to append
        tail = newNode;       // Update tail
    }

    void pop()
    {
        if (head == NULL) // If the queue is empty
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node *temp = head; // Save the current head
        head = head->next; // Move the head to the next node

        if (head == NULL) // If the queue becomes empty after popping
        {
            tail = NULL;
        }

        delete temp; // Free the old head
    }

    int front()
    {
        if (head == NULL)
        {
            cout << "Queue is empty!" << endl;
            return -1; // Indicate an error
        }
        return head->val;
    }

    int back()
    {
        if (tail == NULL)
        {
            cout << "Queue is empty!" << endl;
            return -1; // Indicate an error
        }
        return tail->val;
    }

    bool empty()
    {
        return head == NULL;
    }

    int size()
    {
        Node *temp = head;
        int count = 0;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // print queue
    void print_queue()
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    MyQueue ticket;

    ticket.push(20);
    ticket.push(10);
    ticket.push(40);
    ticket.push(50);

    cout << "Queue contents:" << endl;
    ticket.print_queue();

    cout << "Front: " << ticket.front() << endl;
    cout << "Back: " << ticket.back() << endl;

    ticket.pop();
    cout << "After one pop:" << endl;
    ticket.print_queue();

    cout << "Queue size: " << ticket.size() << endl;
    cout << "Is queue empty? " << (ticket.empty() ? "Yes" : "No") << endl;

    return 0;
}
