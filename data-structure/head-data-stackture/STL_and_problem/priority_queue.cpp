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

    // maximum priority queue
    priority_queue<int> pq;
    pq.push(10);
    pq.push(299);
    pq.push(383);
    // get top priory
    cout << pq.top() << endl;

    // minimum priority queue
    priority_queue<int, vector<int>, greater<int>> minPq;
    minPq.push(10);
    minPq.push(299);
    minPq.push(383);

    // get min priority queue get top
    cout << minPq.top() << endl;

    return 0;
}
