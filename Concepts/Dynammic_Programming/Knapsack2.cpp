#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int N, weight;
    long long W, value;
    cin >> N >> W;

    vector<long long> values(N);
    vector<long long> weights(N);

    long long sum_values = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> weight >> value;
        sum_values += value;
        values[i] = value;
        weights[i] = weight;
    }
    vector<long long> dp(sum_values + 1, 1000000000000000ll);

    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = sum_values - values[i]; j >= 0; j--)
        {
            dp[j + values[i]] = min(dp[j+values[i]], dp[j] + weights[i]);
        }
    }

    long long answer = 0;
    for (int i = 0; i <= sum_values; i++)
    {
        if (dp[i] <= W)
        {
            answer = max(answer, (long long) i);
        }
    }
    cout << answer;
    return 0;
}