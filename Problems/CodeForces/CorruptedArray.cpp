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
	int n; cin >> n;
	vector<ll> vals(n + 2);
	for (int i = 0; i < n + 2; i++)
		cin >> vals[i];
	sort(vals.begin(), vals.end());
	ll sum = 0;
	for (int i = 0; i < n + 2; i++) {
		sum += vals[i];
	}
	int x = -1;
	int y = -1;
	for (int i = 0; i < n + 2; i++) {
		// assume x = vals[i]
		ll t_sum = sum - vals[i];
		if (i == n + 1) {
			if (t_sum - vals[n] == vals[n]) {
				x = i;
				y = n;
			}
		} else {
			if (t_sum - vals[n + 1] == vals[n + 1]) {
				x = i;
				y = n + 1;
			}
		}
	}
	vector<ll> ans;
	if (x == -1) {
		return {};
	}
	for (int i = 0; i < n + 2; i++) {
		if (i == x || i == y)
			continue;
		ans.pb(vals[i]);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		vector<ll> res = solve();
		if (res.empty()) {
			cout << -1 << endl;
		} else {
			for (ll val : res) {
				cout << val << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
