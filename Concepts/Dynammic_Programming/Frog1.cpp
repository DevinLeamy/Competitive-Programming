#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 5;

int main()
{
    int N, S;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++)
    {
        cin >> S;
        h[i] = S;
    }
    //dp[i] -> Minimum cost to get to the ith stone
    vector<int> dp(N, INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j : {i + 1, i + 2})
        {
            if (j < N)
            {
                dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
            }
        }
    }
    cout << dp[N-1];

    return 0;
}
