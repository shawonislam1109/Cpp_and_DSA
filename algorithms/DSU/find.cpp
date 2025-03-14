#include <iostream>
#include <vector>

using namespace std;

int find(int val, vector<int> &leaders)
{
    // while (leaders[val] != -1)
    // {
    //     val = leaders[val];
    // }
    // return val;

    // this code use for recursion
    if (leaders[val] == -1)
        return val;
    return find(leaders[val], leaders);
}

int main()
{
    vector<int> leaders(6, -1);

    leaders[0] = 1;
    leaders[1] = -1;
    leaders[2] = 1;
    leaders[3] = 1;
    leaders[4] = 2;
    leaders[5] = 3;

    cout << find(3, leaders) << endl;

    return 0;
}
