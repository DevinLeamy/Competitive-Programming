#include <iostream>
#include <vector>

using namespace std;

int days[100001][3], dp[100001][3];
int INF = 10e8 + 1;
int main() {
    int a, b, c, n;
    scanf("%i", &n);
    for (int i = 0; i < n; i++) {
        scanf("%i%i%i", &a, &b, &c);
        days[i][0] = a;
        days[i][1] = b;
        days[i][2] = c;
    }
    dp[0][0] = days[0][0];
    dp[0][1] = days[0][1];
    dp[0][2] = days[0][2];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + days[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + days[i][1];
        dp[i][2] = max(dp[i-1][1], dp[i-1][0]) + days[i][2];
    }
    cout << max( max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << endl;
    return 0;
}
