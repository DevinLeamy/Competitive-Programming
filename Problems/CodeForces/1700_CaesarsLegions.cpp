#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#define INF 2147483647
#define LINF 9223372036854775807ll
#define PI pair<int, int>
#define PL pair<long long, long long>
#define ll long long
#define pb push_back
#define loop(h) while(h--)
using namespace std;
char _;

ll mod = 100000000;
ll dp[101][101][11][11];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;
	dp[0][1][0][1] = 1;
	dp[1][0][1][0] = 1;
	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
			for (int k = 0; k <= k1; k++) {
				if (k != k1 && i != n1) {
					dp[i+1][j][k+1][0] += dp[i][j][k][0];
					dp[i+1][j][k+1][0] %= mod;
				}
				if (j != n2) {
					dp[i][j+1][0][1] += dp[i][j][k][0];
					dp[i][j+1][0][1] %= mod;
				}
			}
			for (int l = 0; l <= k2; l++) {
				if (l != k2 && j != n2) {
					dp[i][j+1][0][l+1] += dp[i][j][0][l];
					dp[i][j+1][0][l+1] %= mod;
				}
				if (i != n1) {
					dp[i+1][j][1][0] += dp[i][j][0][l];
					dp[i+1][j][1][0] %= mod;
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i <= k1; i++) {
		for (int j = 0; j <= k2; j++) {
			ans += dp[n1][n2][i][j];
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}
