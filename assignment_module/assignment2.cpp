#include <bits/stdc++.h>
using namespace std;
int main()
{
    int res = 0;
    string s;
    getline(cin, s);

    stringstream stream(s);
    string word;
    while (stream >> word)
    {
        if (word == "Jessica")
        {
            res = 1;
            break;
        }
    }

    if (res)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
