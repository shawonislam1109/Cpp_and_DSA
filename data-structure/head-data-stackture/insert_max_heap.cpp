// stdc++.h
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
// Add other commonly used headers as needed
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int insertValue;
    cin >> insertValue;
    arr.push_back(insertValue);

    int curr_ind = arr.size() - 1;

    while (curr_ind != 0)
    {
        int parent_index = (curr_ind - 1) / 2;
        if (arr[parent_index] < arr[curr_ind])
            swap(arr[parent_index], arr[curr_ind]);
        else
            break;
        curr_ind = parent_index;
    }

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
