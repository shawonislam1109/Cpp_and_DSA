#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);

    stringstream stream(s);
    string word;
    stream >> word;
    reverse(word.begin(), word.end());
    cout << word;
    while (stream >> word)
    {
        reverse(word.begin(), word.end());
        cout << " " << word;
    }
    return 0;
}