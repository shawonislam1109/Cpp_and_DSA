#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // this code time complexity is  { o(log n)  }
    for (int i = 0; i < n; i *= 2)
    {
        cout << i << endl;
    }

    // example 2 is
    for (int i = n; i > 1; i /= 3)
    {
        cout << i << endl;
    }

    // example 3 is
    for (int i = 0; i < n; i++)
    {
        cout << i << endl;
        i *= 2;
    }

    return 0;
}