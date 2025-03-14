#include <iostream>
#include <vector>

using namespace std;

int find(int val, int *leaders)
{

    if (leaders[val] == -1)
        return val;
    int findPar = find(leaders[val], leaders);
    leaders[val] = findPar;
    return findPar;
}

int main()
{
    int leaders[105];
    // memset(leaders,-1)
    leaders[0] = 1;
    leaders[1] = -1;
    leaders[2] = 1;
    leaders[3] = 1;
    leaders[4] = 2;
    leaders[5] = 3;

    cout << find(3, leaders) << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << i << " :-> " << leaders[i] << endl;
    }

    return 0;
}
