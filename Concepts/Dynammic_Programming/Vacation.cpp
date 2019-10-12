#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, A;
    cin >> N;
    vector<long long> dp(3, 0);
    for (int i = 0; i < N; i++)
    {
        vector<int> activities(3);
        vector<long long> new_dp(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> A;
            activities[i] = A;
        }
        for (int j = 0; j < 3; j++)
        {
            for (int z = 0; z < 3; z++)
            {
                if (j != z)
                {
                    new_dp[j] = max(new_dp[j], dp[z] + activities[j]);
                }
            }
        }
        for (int j = 0; j < 3; j++)
        {
            dp[j] = new_dp[j];
        }
    }
    long long maxV = -1;
    for (long long value : dp)
    {
        maxV = max(maxV, value);
    }
    cout << maxV;

    return 0;
}