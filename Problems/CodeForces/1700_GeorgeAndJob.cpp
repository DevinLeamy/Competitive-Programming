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
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, m, k; cin >> n >> m >> k;
	vector<ll> vals(n);
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	
	vector<ll> presum(n + 1);
	vector<vector<ll> > dp(k + 1, vector<ll>(n+1));
	for (int i = 0; i < n; i++)
		presum[i + 1] = presum[i] + vals[i];
	
	ll ans = 0;
	for (int i = 1; i <= k; i++) {
		int min = (i - 1) * m;
		int max = (n - (k - i) * m) - m;
		vector<ll> best;
		best.pb(dp[i - 1][min]);
		for (int j = min + 1; j <= max; j++)
			best.pb(std::max(best[j - (min + 1)], dp[i-1][j]));
		for (int j = max; j >= min; j--) {
			dp[i][j + m] = std::max(dp[i][j + m], best[best.size() - (max - j) - 1] + presum[j + m] - presum[j]);
			ans = std::max(ans, dp[i][j + m]);
		}
	}
	cout << ans << endl;
	return 0;
}
