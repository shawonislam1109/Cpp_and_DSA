#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> list;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        list.insert(x);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int command;
        cin >> command;

        if (command == 1)
        {
            if (!list.empty())
                cout << *list.begin() << endl;
            else
                cout << "Empty" << endl;
        }
        else if (command == 2)
        {
            if (!list.empty())
            {
                list.erase(list.begin());
                if (!list.empty())
                    cout << *list.begin() << endl;
                else
                    cout << "Empty" << endl;
            }
            else
                cout << "Empty" << endl;
        }
        else if (command == 0)
        {
            int x;
            cin >> x;
            list.insert(x);
            cout << *list.begin() << endl;
        }
        else
        {
            cout << "Empty" << endl;
        }
    }

    return 0;
}