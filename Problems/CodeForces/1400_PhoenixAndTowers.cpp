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

vector<int> solve() {
	int n, m, x; cin >> n >> m >> x;
	vector<PI> vals(n);
	for (int i = 0; i < n; i++) {
		cin >> vals[i].first;
		vals[i].second = i;
	}
	sort(vals.rbegin(), vals.rend());
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	vector<ll> towers(m);
	for (int i = 0; i < m; i++)
		q.push({0, i});
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		pair<ll, int> top = q.top(); q.pop();
		towers[top.second] += vals[i].first;
		ans[vals[i].second] = top.second + 1;
		q.push({towers[top.second], top.second});
	}
	ll min = towers[0];
	ll max = towers[0];
	for (int i = 0; i < m; i++) {
		min = std::min(min, towers[i]);
		max = std::max(max, towers[i]);
	}
	if (abs(min - max) > x)
		return {};
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		vector<int> ans = solve();
		if (ans.empty()) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
