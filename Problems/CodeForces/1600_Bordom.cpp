#include <iostream>

using namespace std;

long long dp[100002];
int main() {
    ios_base::sync_with_stdio(0);
    int n, a;
    cin >> n;
    int largestA = -1;
    for (int i = 0; i < n; i++) {
        cin >> a;
        dp[a] += a;
        largestA = max(largestA, a);
    }
    long long inc = dp[0];
    long long excl = 0;
    for (int i = 1; i <= largestA; i++) {
        long long temp = inc;
        inc = max(inc, excl + dp[i]);
        excl = max(temp, excl);
    }
    cout << max(inc, excl) << endl;
}
// At index i || inc = max value attainable including i while excl = max value attainable excluding i
