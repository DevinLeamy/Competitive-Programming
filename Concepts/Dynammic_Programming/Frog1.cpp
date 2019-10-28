#include <iostream>
#include <vector>

using namespace std;

int INF = 10e8 + 1;
int main() {
    int n, h;
    scanf("%i", &n);
    int rocks[n];
    for (int i = 0; i < n; i++) {
        scanf("%i", &h);
        rocks[i] = h;
    }
    int dp[100000];
    for (int i = 0; i <= n; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i+1] = min(dp[i+1], dp[i] + abs(rocks[i+1] - rocks[i]));
        dp[i+2] = min(dp[i+2], dp[i] + abs(rocks[i+2] - rocks[i]));
    }
    cout << dp[n-1] << endl;
    return 0;
}
