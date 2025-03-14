#include <iostream>
#include <set>

using namespace std;

int main()
{
    string c;
    cin >> c;

    sort(c.begin(), c.end());

    c.erase(unique(c.begin(), c.end()), c.end());

    cout << c << endl;
    return 0;
}
