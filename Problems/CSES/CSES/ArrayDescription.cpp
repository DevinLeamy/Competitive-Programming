#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
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
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;

ll dp[100005][105];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	ll mod = 1000000007ll;
	int n, m; cin >> n >> m;
	vector<int> vals(n);
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	
	if (vals[0] == 0) {
		for (int i = 1; i <= m; i += 3) {
			dp[0][i] = 1;
			if (i + 3 > m)
				dp[0][i + 3] = 1;
		}
	} else {
		dp[0][vals[0]] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		if (vals[i - 1] == 0) {
			for (int j = 1; j <= m; j++) {
				ll sum = dp[i - 1][j];
				sum = (sum + dp[i - 1][j - 1]) % mod;
				sum = (sum + dp[i - 1][j + 1]) % mod;
				dp[i][j] = sum;
			}
		} else {
			ll sum = dp[i - 1][vals[i - 1]];
			sum = (sum + dp[i - 1][vals[i - 1] - 1]) % mod;
			sum = (sum + dp[i - 1][vals[i - 1] + 1]) % mod;
			dp[i][vals[i - 1]] = sum;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= m; i++)
		ans = (ans + dp[n][i]) % mod;
	cout << ans << "\n";
	return 0;
}
