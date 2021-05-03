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
#define view2(a, b) cout << "DEBUG: " << a << " " << b << endl;
using namespace std;
char _;

ll dp[5005][5005];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, m; cin >> n >> m;
	string s1, s2; cin >> s1 >> s2;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 2ll;
			dp[i][j] = max(dp[i - 1][j] - 1ll, dp[i][j]);
			dp[i][j] = max(dp[i][j - 1] - 1ll, dp[i][j]);
			dp[i][j] = max(0ll, dp[i][j]);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}
