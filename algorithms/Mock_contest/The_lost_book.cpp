#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long int> a(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int res = -1;

    long long int q;
    cin >> q;
    for (long long int i = 0; i < n; i++)
    {
        if (a[i] == q)
        {
            res = i;
            break;
        }
    }
    cout << res;

    return 0;
}
