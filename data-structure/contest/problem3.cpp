#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int K;
    cin >> K;
    K = K % N;
    vector<int> rotated(N);
    for (int i = 0; i < N; i++)
    {
        rotated[(i + K) % N] = A[i];
    }
    while (Q--)
    {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        int sum = 0;
        for (int i = L; i <= R; i++)
        {
            sum += rotated[i];
        }
        cout << sum << endl;
    }
    return 0;
}
