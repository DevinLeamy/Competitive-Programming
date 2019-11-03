//Not on github

#include <iostream>

using namespace std;

long long MOD = 1000000007;
long long dp[100001];
void fib();
int len;
int main() {
    string M;
    cin >> M;
    bool zero = false;
    long long count = 1;
    len = (int) M.length();
    fib();
    for (int i = 0; i < len; i++) {
        if (M[i] == 'w' || M[i] == 'm') {zero = true; break;}
        if (M[i] == 'u') {
            int mult = 1;
            i++;
            while (M[i] == 'u' && i < len) {
                i++;
                mult++;
            }
            i--;
            count *= dp[mult];
        } else if (M[i] == 'n') {
            int mult = 1;
            i++;
            while (M[i] == 'n' && i < len) {
                i++;
                mult++;
            }
            i--;
            count *= dp[mult];
        }
        count %= MOD;
    }
    cout << ((zero)? 0 : count) << endl;
    return 0;
}
void fib() {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= len; i++) {
        dp[i] = (dp[i-1] + dp[i-2]);
        if (dp[i] >= MOD) {
            dp[i] -= MOD;
        }
    }
}
