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

// class Node
// {
// public:
//     int val;
//     Node *next;
//     Node(int val)
//     {
//         this->val = val;
//         this->next = NULL;
//     }
// };

// this code  when reference pass by in function for this code
void func(int *&p)
{
    p = NULL;
};

// without reference. pass by pointer not changing in main
void without_reference(int *p)
{
    int y = 300;
    p = &y;
};

int main()
{
    int x = 20;
    int *p = &x;

    func(p);

    cout << "main in " << *p << endl;
    return 0;
}
