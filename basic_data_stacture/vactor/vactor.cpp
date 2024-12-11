#include <bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> v;                     // type 1
    // vector<int> v1(10, 0);             // type 2
    // vector<int> v2(v1);                // type 3
    // vector<int> v = {1, 53, 5, 3, 23}; // type 3
    // int arr[5] = {12, 3, 52, 12};      // type 5
    // vector<int> v3(arr, arr + 5);      // type 6
    //                                    // this 6 way dclear vector defined

    // // vector capacity function

    // v2.size();
    // v2.max_size();
    // v2.capacity();
    // v2.resize(10, 20);

    vector<int> v = {1, 2, 3, 4};
    // v.resize(2);
    // v.resize(4);
    v.erase(v.begin() + 2, v.end());

    for (int s : v)
    {
        cout << s << " ";
    }
    return 0;
}