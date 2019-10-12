#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 5;

int main()
{
    int N, K, S;
    cin >> N >> K;
    vector<int> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> S;
        H[i] = S;
    }
    vector<int> dp(N, INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j <= i+K; j++)
        {
            if (j < N)
            {
                dp[j] = min(dp[j], dp[i] + abs(H[i] - H[j]));
            }
        }
    }
    cout << dp[N-1];

    return 0;
}
