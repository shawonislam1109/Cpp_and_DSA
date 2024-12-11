#include <bits/stdc++.h>
using namespace std;

// -> problem new array

int main()
{
    int n;
    cin >> n;
    vector<int> v;

    // time complexity order of o(n)
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x < 0 && x != 0)
        {
            v.push_back(2);
        }
        else if (x > 0)
        {
            v.push_back(1);
        }
        else
        {
            v.push_back(0);
        }
    }

    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}