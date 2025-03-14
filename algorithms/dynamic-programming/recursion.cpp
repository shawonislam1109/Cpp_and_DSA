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
void recursion(int s)
{
    if (s == 5)
    {
        return;
    }

    recursion(s + 1);
    cout << s << " ";
}

int main()
{
    recursion(1);
    return 0;
}