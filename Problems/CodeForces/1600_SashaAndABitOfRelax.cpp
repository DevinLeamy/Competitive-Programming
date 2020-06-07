#include <iostream>
using namespace std;

int dp[2][1048577];
long long values[300001];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    long long a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        values[i] = a;
    }
    long long result = 0;
    int x = 0;
    dp[1][0] = 1;
    for (int i = 0; i < n; i++) {
        x ^= values[i];
        result += dp[i%2][x];
        dp[i%2][x]++;
    }
    cout << result << endl;
}

