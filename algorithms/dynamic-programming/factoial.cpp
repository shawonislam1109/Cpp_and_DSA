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

int factorial(int s)
{
    if (s < 1)
    {
        return 1;
    }
    return s * factorial(s - 1);
};
int main()
{
    cout << factorial(3);
    return 0;
}
