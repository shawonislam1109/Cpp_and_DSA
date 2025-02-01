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
    Node a(29), b(73), c(883);

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    // cout << " " << a.val << " " << b.val << " " << c.val << endl;

    // LINKED LIST DATA ACCESS FROM THE NODE
    cout << a.val << " " << a.next->val << " " << a.next->next->val << endl;
    return 0;
}
