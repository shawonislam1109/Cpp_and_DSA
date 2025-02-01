#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> customers(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> customers[i].first >> customers[i].second;
    }

    int current_time = 0;
    int unsatisfied = 0;

    for (int i = 0; i < n; ++i)
    {
        int arrival_time = i + 1;
        int max_time = customers[i].first;
        int service_time = customers[i].second;

        int waiting_time = current_time - arrival_time;

        if (waiting_time > max_time)
        {
            unsatisfied++;
        }
        else
        {
            current_time = arrival_time + service_time;
        }
    }

    cout << unsatisfied << endl;

    return 0;
}