#include <iostream>

using namespace std;

long long dp[1001][1001];
bool canTravel[1001][1001];
long long mod = 1000000007;
int main () {
    ios_base::sync_with_stdio(0);
    int H, W; string row;
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        cin >> row;
        for (int j = 1; j <= W; j++) {
            canTravel[i][j] = (row[j-1] == '.');
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (!canTravel[i][j]) {continue;}
            dp[i][j] += dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[H][W] << endl;
}
