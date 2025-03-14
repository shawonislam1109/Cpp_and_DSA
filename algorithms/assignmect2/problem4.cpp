#include <iostream>
#include <vector>
using namespace std;

void maxWaterContainerOptimized(int n, vector<int> &height)
{
    int left = 0, right = n - 1;
    int maxWater = 0, bestLeft = 0, bestRight = 0;

    while (left < right)
    {
        int water = min(height[left], height[right]) * (right - left);

        if (water > maxWater)
        {
            maxWater = water;
            bestLeft = left;
            bestRight = right;
        }

        // Move the pointer with the smaller height
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    cout << bestLeft << " " << bestRight << endl; // Output the correct indices
}

int main()
{
    int t;
    cin >> t; // Number of test cases

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> height(n);

        for (int i = 0; i < n; i++)
            cin >> height[i];

        maxWaterContainerOptimized(n, height);
    }

    return 0;
}
