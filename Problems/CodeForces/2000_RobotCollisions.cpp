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

int n; ll m;
vector<ll> ans(300005);
void solve(set<pair<ll, int> > left, set<pair<ll, int> > right) {
	vector<pair<ll, int>> remove;
	for (auto i = right.rbegin(); i != right.rend(); i++) {
		pair<ll, int> val = *i;
		auto itr = left.upper_bound(val);
		if (itr == left.end()) {
			continue;
		} else {
			pair<ll, int> val2 = *itr;
			ll pos = val2.first;
			int idx = val2.second;
			ans[idx] = abs(val.first - pos) / 2;
			ans[val.second] = abs(val.first - pos) / 2;
			left.erase(val2);
			remove.pb(val);
		}
	}
	for (pair<ll, int> val : remove)
		right.erase(val);
	
	vector<pair<ll, int> > right_v;
	vector<pair<ll, int> > left_v;
	for (auto it = right.begin(); it != right.end(); it++)
		right_v.pb(*it);
	
	for (auto it = left.begin(); it != left.end(); it++)
		left_v.pb(*it);
	
	for (int i = (int) right_v.size() - 1; i >= 0; i -= 2) {
		if (i == 0)
			break;
		pair<ll, int> cur = right_v[i];
		pair<ll, int> next = right_v[i - 1];
		ll to_wall = m - cur.first;
		ll dist = abs(cur.first - next.first);
		ll time = to_wall + dist / 2;
		ans[cur.second] = time;
		ans[next.second] = time;
	}
	for (int i = 0; i < (int) left_v.size(); i += 2) {
		if (i == (int) left_v.size() - 1)
			break;
		pair<ll, int> cur = left_v[i];
		pair<ll, int> next = left_v[i + 1];
		ll to_wall = cur.first;
		ll dist = abs(cur.first - next.first);
		ll time = to_wall + dist / 2;
		ans[cur.second] = time;
		ans[next.second] = time;
	}
	if (right_v.size() % 2 == 1 && left_v.size() % 2 == 1) {
		pair<ll, int> lft = left_v.back();
		pair<ll, int> rgt = right_v[0];
		ll dist = m - rgt.first + lft.first + abs(rgt.first - lft.first) / 2;
		ans[lft.second] = dist;
		ans[rgt.second] = dist;
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		ans[i] = -1;
	vector<pair<ll, pair<int, bool> > > vals(n);
	for (int i = 0; i < n; i++) {
		vals[i].second.first = i;
		cin >> vals[i].first;
	}
		
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		vals[i].second.second = c == 'L';
	}
	set<pair<ll, int> > left_even;
	set<pair<ll, int> > left_odd;
	set<pair<ll, int> > right_even;
	set<pair<ll, int> > right_odd;
	
	for (pair<ll, pair<int, bool> > val : vals) {
		if (val.first % 2 == 0) {
			if (val.second.second) {
				left_even.insert(make_pair(val.first, val.second.first));
			} else {
				right_even.insert(make_pair(val.first, val.second.first));
			}
		} else {
			if (val.second.second) {
				left_odd.insert(make_pair(val.first, val.second.first));
			} else {
				right_odd.insert(make_pair(val.first, val.second.first));
			}
		}
	}
	solve(left_even, right_even);
	solve(left_odd, right_odd);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		solve();
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}
