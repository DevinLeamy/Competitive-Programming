#include <iostream>

using namespace std;


int main()
{
    int N, K;
    cin >> N >> K;
    int diff[N+1];
    int same[N+1];
    int total[N+1];
    for (int i = 0; i <= N; i++)
    {
        diff[i] = 0;
        same[i] = 0;
        total[i] = 0;
    }
    diff[1] = K;
    total[1] = K;
    for (int i = 2;i <= N; i++)
    {
        diff[i] = total[i-1] * (K-1);
        same[i] = diff[i-1];
        total[i] = diff[i] + same[i];
    }
    cout << total[N];

    return 0;
}
