#include <iostream>
using namespace std;

bool findOut(int T)
{
    for (int i = 0; i * 3 <= T; i++)
    {
        if ((T - i * 3) % 4 == 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int T;
    cin >> T;

    if (findOut(T))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
