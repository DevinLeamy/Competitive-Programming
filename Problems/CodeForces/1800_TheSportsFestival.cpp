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
	int n; cin >> n;
	vector<ll> vals(n);
	for (int i = 0; i < n; i++) {
		ll val; cin >> val;
		vals[i] = val;
	}
	sort(vals.begin(), vals.end());
	vector<vector<ll>> dp(n + 5, vector<ll>(n + 5));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + vals[j] - vals[i];
		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}
