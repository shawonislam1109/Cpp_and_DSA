#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_balls(int n, vector<int> &arr)
{

    sort(arr.begin(), arr.end(), greater<int>());

    int last_taken = INT_MAX;
    int total_balls = 0;

    for (int balls : arr)
    {
        if (balls < last_taken)
        {
            total_balls += balls;
            last_taken = balls;
        }
        else
        {

            if (last_taken > 1)
            {
                total_balls += last_taken - 1;
                last_taken -= 1;
            }
            else
            {
                break;
            }
        }
    }

    return total_balls;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << max_balls(n, arr) << endl;

    return 0;
}
