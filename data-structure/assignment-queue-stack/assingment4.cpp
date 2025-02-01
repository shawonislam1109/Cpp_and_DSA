
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <functional>
#include <utility>
#include <iomanip>
#include <fstream>
#include <list>

using namespace std;

int main()
{
    int q;
    cin >> q;

    queue<string> line;

    while (q--)
    {
        string command;
        cin >> command;

        if (command == "0")
        {
            string name;
            cin >> name;
            line.push(name);
        }
        else if (command == "1")
        {
            if (!line.empty())
            {
                cout << line.front() << endl;
                line.pop();
            }
            else
            {
                cout << "Invalid" << endl;
            }
        }
    }

    return 0;
}