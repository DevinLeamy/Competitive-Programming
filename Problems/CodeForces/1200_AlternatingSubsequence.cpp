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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n; ll a;
		bool pos = true;
		cin >> n;
		vector<vector<ll>> vals;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (vals.size() == 0) {
				pos = a > 0;
				vals.pb({a});
			}
			if (a > 0) {
				if (pos) {
					vals[vals.size()-1].pb(a);
				} else {
					pos = true;
					vals.pb({a});
				}
			} else {
				if (!pos) {
					vals[vals.size()-1].pb(a);
				} else {
					pos = false;
					vals.pb({a});
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i < vals.size(); i++) {
			ll max = -LINF;
			for (ll val : vals[i]) {
				max = std::max(val, max);
			}
			ans += max;
		}
		cout << ans << "\n";
	}
	return 0;
}
