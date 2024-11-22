#include <bits/stdc++.h>
using namespace std;

int *fun()
{
    int *arr = new int[3];

    for (int i = 0; i < 3; i++)
    {
        *(arr + i) = i + 1;
    }
    return arr;
}

int main()
{

    int *main_array = fun();

    for (int i = 0; i < 3; i++)
    {
        cout << *(main_array + i) << " ";
    }

    // int *dynamic = new int[5];

    // for (int i = 0; i < 5; i++)
    // {
    //     *(dynamic + i) = i + 1;

    //     cout << *(dynamic + i) << " ";
    // }
}