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

int MAXN = 100005;
int n, m;
vector<int> init(MAXN);
vector<int> des(MAXN);
vector<int> paint(MAXN);
vector<vector<int>> change(MAXN, vector<int>());
vector<int> ans(MAXN);
vector<int> solve() {
	cin >> n >> m;
	vector<int> wanted(n + 1, -1);
	for (int i = 0; i <= n; i++)
		change[i].clear();
	for (int i = 0; i < n; i++)
		cin >> init[i];
	for (int i = 0; i < n; i++) {
		cin >> des[i];
		wanted[des[i]] = i;
		if (init[i] != des[i])
			change[des[i]].pb(i);
	}
	for (int i = 0; i < m; i++)
		cin >> paint[i];
	vector<int> fill;
	for (int i = 0; i < m; i++) {
		int col = paint[i];
		if (change[col].empty()) {
			fill.pb(i);
		} else {
			for (int idx : fill)
				ans[idx] = change[col].back();
			ans[i] = change[col].back();
			change[col].pop_back();
			fill.clear();
			continue;
		}
		if (wanted[col] != -1) {
			for (int idx : fill)
				ans[idx] = wanted[col];
			fill.clear();
		}
	}
	for (int i = 0; i <= n; i++) {
		if (!change[i].empty())
			return {};
	}
	if (fill.empty())
		return ans;
	return {};
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		vector<int> res = solve();
		if (res.empty()) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (int i = 0; i < m; i++)
				cout << ans[i] + 1 << " ";
			cout << "\n";
		}
	}
	return 0;
}
