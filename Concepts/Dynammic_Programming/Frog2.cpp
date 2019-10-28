#include <iostream>
#include <vector>

using namespace std;

int INF = 10e8 + 1;
int rocks[100001];
int dp[100000];
int main() {
    int n, k, h;
    scanf("%i%i", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%i", &h);
        rocks[i] = h;
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i+j] = min(dp[i+j], dp[i] + abs(rocks[i] - rocks[i+j]));
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}
