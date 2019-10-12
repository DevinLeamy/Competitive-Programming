#include <iostream>

using namespace std;

int main()
{
    int R, C, E;
    cin >> R >> C;
    int matrix[R][C];
    int dp[R+1][C+1];
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> E;
            matrix[i][j] = E;
        }
    }
    for (int i = 0; i <= R; i++)
    {
        for (int j = 0; j <= C; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + matrix[i-1][j-1];
        }
    }
    for (int i = 1; i <= R; i++)
    {
        cout << endl;
        for (int j = 1; j <= C; j++)
        {
            cout << dp[i][j] << " ";
        }
    }
    cout << dp[R][C] << endl;
}

