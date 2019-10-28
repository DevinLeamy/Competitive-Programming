#include <iostream>

using namespace std;

string dp[3001][3001];
int main() {
    ios_base::sync_with_stdio(0);
    string top, bottom;
    cin >> top >> bottom;
    for (int i = 1; i <= top.length(); i++) {
        for (int j = 1; j <= bottom.length(); j++) {
            if (top[i-1] == bottom[j-1]) {
                dp[i][j] += top[i-1];
            }
            string newString;
            newString = dp[i-1][j];
            if (dp[i][j-1].length() > newString.length()) {newString = dp[i][j-1];}
            if ((dp[i-1][j-1] + dp[i][j]).length() > newString.length()) {newString = dp[i-1][j-1] + dp[i][j];}
            dp[i][j] = newString;
        }
    }
    cout << dp[top.length()][bottom.length()] << endl;
}
