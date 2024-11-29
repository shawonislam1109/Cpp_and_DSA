#include <bits/stdc++.h>
using namespace std;

int main()
{
    //  str modify common functions
    string s = "Hello world";
    s[3] = 'H';

    cout << s << endl;

    // iterator stirng
    for (auto it = s.begin(); it < s.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}