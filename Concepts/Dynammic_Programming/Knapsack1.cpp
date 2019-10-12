#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int N, W, weight;
    long long value;
    cin >> N >> W;

    vector<long long> dp(W+1);

    for (int i = 0; i < N; i++)
    {
        cin >> weight >> value;
        for (int j = W-weight; j >= 0; j--)
        {
            dp[j + weight] = max(dp[j + weight], dp[j] + value);
        }
    }
    long long answer = 0;
    for (int i = 0; i <= W; i++)
    {
        answer = max(answer, dp[i]);
    }
    cout << answer;
    return 0;
}