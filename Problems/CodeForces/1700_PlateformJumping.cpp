#include <iostream>
#include <vector>
using namespace std;

int dp[1001];
int main() {
    ios_base::sync_with_stdio(0);
    int n, m, d, c;
    cin >> n >> m >> d;
    int current = -1;
    string output = "";
    for (int i = 0; i < m; i++) {
        current = min((current+d), n);
        cin >> c;
        int overflow = 0;
        int hold = 0;
        for (int j = current; j < current+c; j++) {
            if (j >= n) {overflow++; continue;}
            dp[j] = (i+1);
            hold = j;
        }
        for (int j = current-1; j >= current-overflow; j--) {
            hold = max(hold, j);
            if (dp[j] != 0) {
                int current = j;
                int temp = dp[current];
                dp[current] = (i+1);
                current--;
                while (dp[current] != 0) {
                    int hold = dp[current];
                    dp[current] = temp;
                    temp = hold;
                    current--;
                    
                }
                dp[current] = temp;
            } else {dp[j] = i+1;}
        }
        current = hold;
    }
    if (current >= n-d) {
        for (int i = 0; i < n; i++) { output += to_string(dp[i]); output += " ";}
        cout << "YES" << endl;
        cout << output << endl;
    } else {cout << "NO" << endl;}
    return 0;
}
