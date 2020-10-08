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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n, m; cin >> n >> m;
		vector<vector<ll>> vals;
		for (int i = 0; i < n; i++) {
			vals.pb(vector<ll>(m));
			for (int j = 0; j < m; j++) {
				cin >> vals[i][j];
			}
		}
		ll ans = 0;
		for (int i = 0; i < (n/2 + n%2); i++) {
			for (int j = 0; j < (m/2 + m%2); j++) {
				ll a = vals[i][j];
				ll b = vals[n-1-i][j];
				ll c = vals[n-1-i][m-1-j];
				ll d = vals[i][m-1-j];
				vector<ll> nums = { a, b, c, d};
				ll minC = LINF;
				for (ll num : nums) {
					ll cost = 0;
					for (ll num2 : nums) {
						cost += abs(num - num2);
					}
					minC = min(cost, minC);
				}
				if (i == n-1-i) minC /= 2;
				if (j == m-1-j) minC /= 2;
				ans += minC;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
