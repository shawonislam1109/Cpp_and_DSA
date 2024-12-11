#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v = {1, 2, 2, 23, 2, 2};

    // v.pop_back();
    // v.insert(v.begin() + 3, 300);
    // v.erase(v.begin(), v.begin() + 3);
    // replace(v.begin(), v.end() - 3, 2, 300);

    // vector<int>::iterator it = find(v.begin(), v.end(), 6);
    // iterator sort curt is

    auto it = find(v.begin(), v.end(), 2);

    if (it == v.end())
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "Yes found" << endl;
    }

    for (int x : v)
    {
        cout << x << " ";
    }

    cout << endl
         << v.size();

    return 0;
}