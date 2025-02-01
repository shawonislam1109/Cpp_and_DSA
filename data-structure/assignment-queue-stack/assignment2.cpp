#include <iostream>
#include <stdexcept>

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

class MyStack
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void pushStack(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    bool empty()
    {
        return head == NULL;
    }

    int top()
    {
        if (tail != NULL)
            return tail->val;
        throw runtime_error("Stack is empty");
    }

    void popStack()
    {
        if (tail == NULL)
            return;

        if (head == tail)
        {
            delete tail;
            head = NULL;
            tail = NULL;
            return;
        }

        Node *prevTail = tail->prev;
        prevTail->next = NULL;
        delete tail;
        tail = prevTail;
    }

    void PrintNode()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class MyQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void pushQueue(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    bool empty()
    {
        return head == NULL;
    }

    int top()
    {
        if (head != NULL)
            return head->val;
        throw runtime_error("Queue is empty!");
    }

    void popQueue()
    {
        if (head == NULL)
            return;

        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        Node *nextHead = head->next;
        nextHead->prev = NULL;
        delete head;
        head = nextHead;
    }

    void PrintNode()
    {
        Node *temp = head;
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
    MyStack st;
    MyQueue qu;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.pushStack(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        qu.pushQueue(x);
    }

    if (n != m)
    {
        cout << "NO" << endl;
        return 0;
    }

    while (!st.empty() && !qu.empty())
    {
        if (st.top() != qu.top())
        {
            cout << "NO" << endl;
            return 0;
        }
        st.popStack();
        qu.popQueue();
    }

    // If all elements matched
    cout << "YES" << endl;
    return 0;
}
