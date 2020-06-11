#include <iostream>
using namespace std;

int dp[8001];
int main() {
    ios_base::sync_with_stdio(0);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int nums[3] = {a, b, c};
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (dp[i] <= 0) {continue;}
        for (int num : nums) {
            dp[i+num] = max(dp[i+num], dp[i] + 1);
        }
    }
    cout << (dp[n] - 1) << endl;
}
