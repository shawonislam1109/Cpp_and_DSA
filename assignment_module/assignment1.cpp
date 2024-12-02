#include <bits/stdc++.h>
using namespace std;

void replaceAndPrint(const string &A, const string &B)
{
    string result;
    int i = 0;
    int n = A.size();
    int m = B.size();

    while (i < n)
    {
        if (i + m <= n && A.substr(i, m) == B)
        {
            result += '#';
            i += m;
        }
        else
        {
            result += A[i];
            i++;
        }
    }

    cout << result << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string A, B;
        cin >> A >> B;
        replaceAndPrint(A, B);
    }

    return 0;
}
