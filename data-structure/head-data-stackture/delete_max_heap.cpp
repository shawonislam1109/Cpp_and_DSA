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

    // Swap first and last elements
    swap(arr[0], arr[n - 1]);

    // Remove the last element
    arr.pop_back();
    n--; // Adjust n

    // Current index for heap adjustment
    int curr_ind = 0;

    while (curr_ind < n)
    {
        int left_ind = (curr_ind * 2) + 1;
        int right_ind = (curr_ind * 2) + 2;
        int largest = curr_ind;

        // Check left child
        if (left_ind < n && arr[largest] < arr[left_ind])
        {
            largest = left_ind;
        }

        // Check right child
        if (right_ind < n && arr[largest] < arr[right_ind])
        {
            largest = right_ind;
        }

        // If no swaps are needed, break
        if (largest == curr_ind)
            break;

        // Swap with the largest child
        swap(arr[curr_ind], arr[largest]);
        curr_ind = largest;
    }

    // Print the result
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}