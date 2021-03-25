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

vector<ll> solve() {
	int n, m; cin >> n >> m;
	vector<pair<int, ll>> starts;
	vector<pair<int, ll>> ends;
	vector<pair<PI, ll>> querys;
	for (int i = 0; i < m; i++) {
		int l, r; ll a; cin >> l >> r >> a;
		l--; r--;
		starts.pb({l, a});
		ends.pb({r, a});
		querys.pb({{l, r}, a});
	}
	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end());
	int sp = 0, ep = 0;
	vector<int> cnt(31);
	vector<vector<int>> presums(n + 1, vector<int>(31));
	presums[0] = vector<int>(31);
	vector<ll> ans;
	for (int i = 0; i < n; i++) {
		while (sp != starts.size() && i >= starts[sp].first) {
			pair<int, ll> start = starts[sp];
			for (int j = 0; j <= 30; j++) {
				if (start.second & (1ll << j)) {
					cnt[j]++;
				}
			}
			sp++;
		}
		ll val = 0;
		for (int j = 0; j < 31; j++) {
			if (cnt[j] >= 1) {
				val += (1ll << j);
			}
		}
		ans.pb(val);
		for (int j = 0; j < 31; j++)
			presums[i + 1][j] = presums[i][j] + ((cnt[j] > 0)? 1 : 0);

		while (ep != ends.size() && i >= ends[ep].first) {
			pair<int, ll> end = ends[ep];
			for (int j = 0; j < 31; j++) {
				if (end.second & (1ll << j)) {
					cnt[j]--;
				}
			}
			ep++;
		}
	}
	for (pair<PI, ll> query : querys) {
		int l = query.first.first;
		int r = query.first.second;
		ll val = query.second;
		for (int i = 0; i < 31; i++) {
			if (val & (1ll << i))
				continue;
			int diff = presums[r + 1][i] - presums[l][i];
			if (diff > 0 && diff >= r - l + 1)
				return {};
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	vector<ll> res = solve();
	if (res.empty()) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		for (ll val : res) {
			cout << val << " ";
		}
		cout << "\n";
	}
	return 0;
}
