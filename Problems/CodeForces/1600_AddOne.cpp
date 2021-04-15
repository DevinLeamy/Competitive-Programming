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

ll mod = 1000000007ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	vector<vector<ll>> dp(200015, vector<ll>(10));
	vector<ll> totals(200015);
	dp[0][0] = 1;
	for (int i = 1; i < 200015; i++) {
		for (int j = 1; j < 10; j++) {
			dp[i][j] = dp[i-1][j - 1];
		}
		dp[i][0] = dp[i - 1][9];
		dp[i][1] = (dp[i][1] + dp[i - 1][9]) % mod;
	}
	for (int i = 0; i < 200015; i++) {
		for (ll val : dp[i]) {
			totals[i] = (totals[i] + val) % mod;
		}
	}
	loop(t) {
		string s; cin >> s;
		int m; cin >> m;
		vector<int> cnts(10);
		for (int i = 0; i < s.length(); i++)
			cnts[s[i] - '0']++;
		ll ans = 0;
		for (int i = 0; i < 10; i++) {
			int idx = i + m;
			ans = (ans + (cnts[i] * totals[idx])) % mod;
		}
		cout << ans << endl;
		
	}
	return 0;
}
