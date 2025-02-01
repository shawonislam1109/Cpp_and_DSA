#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int q;
    cin >> q;

    stack<int> machine;
    int sum = 0;

    while (q--)
    {
        int key;
        cin >> key;

        if (key == 1)
        {
            cout << sum << endl;
        }
        else if (key == 2)
        {
            int value;
            cin >> value;
            sum += value;
            machine.push(value);
        }
        else if (key == 3)
        {
            if (!machine.empty())
            {
                int lastAdded = machine.top();
                machine.pop();
                sum -= lastAdded;
            }
        }
    }

    return 0;
}