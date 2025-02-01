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

int main()
{
    Node *head = new Node(29);
    Node *b = new Node(237);
    Node *c = new Node(2976);
    Node *d = new Node(295);

    head->next = b;
    b->next = c;
    c->next = d;

    // liked list this kind of print is longly process  i want to different
    cout << head->val << " " << head->next->val << " " << head->next->next->val << " " << head->next->next->next->val << endl;

    // we can not reassign head  cause we do another work with head that way we can't reassign head
    Node *temp = head;

    //  we want to see simple and short curt process
    while (temp->next != NULL)
    {
        cout << temp->val << " " << endl;
        temp = temp->next;
    }

    return 0;
}
