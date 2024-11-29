#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);

    // cout << s;

    stringstream stream(s);
    string word;
    while (stream >> word)
    {
        cout << word << endl;
    }

    return 0;
}
