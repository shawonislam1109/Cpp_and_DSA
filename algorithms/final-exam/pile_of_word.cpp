#include <iostream>
#include <algorithm>
using namespace std;

bool isPileOfWord(string a, string b)
{
    if (a.length() != b.length())
        return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string a, b;
        cin >> a >> b;
        if (isPileOfWord(a, b))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
