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

vector<ll> solve() {
	int n; cin >> n;
	vector<pair<int, ll>> vals(n);
	vector<vector<ll>> uni(n, vector<ll>());
	for (int i = 0; i < n; i++) {
		cin >> vals[i].first;
		vals[i].first--;
	}
	for (int i = 0; i < n; i++) {
		cin >> vals[i].second;
		uni[vals[i].first].pb(vals[i].second);
	}
	vector<ll> ans(n);
	for (int i = 0; i < n; i++) {
		sort(uni[i].begin(), uni[i].end());
		uni[i].pb(0ll);
		reverse(uni[i].begin(), uni[i].end());
		for (int j = 1; j < uni[i].size(); j++) {
			uni[i][j] = uni[i][j - 1] + uni[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= min(n, (int) uni[i].size()); j++) {
			ans[j - 1] += uni[i][((uni[i].size() - 1) / j) * j];
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		vector<ll> ans = solve();
		for (ll val : ans)
			cout << val << " ";
		cout << endl;
	}
	return 0;
}
