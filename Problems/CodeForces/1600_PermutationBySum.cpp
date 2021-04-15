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

vector<int> solve() {
	int n, l, r, s;
	cin >> n >> l >> r >> s;
	l--; r--;
	int len = r - l + 1;
	vector<int> seg(len);
	vector<bool> taken(n + 1);
	
	int cur = n;
	s -= (len * (len + 1)) / 2;
	for (int i = len; i >= 1; i--) {
		while ((cur != 0 && s < cur) || cur + i > n) {
			cur--;
		}
		if (cur < 0 || s < cur) {
			return {};
		}
		int take = min(s, cur);
		s -= take;
		taken[cur + i] = true;
		seg[i - 1] = take + i;
	}
	if (s != 0)
		return {};
	vector<int> ans(n);
	cur = n;
	for (int i = 0; i < n; i++) {
		if (i >= l && i <= r) {
			ans[i] = seg.back();
			seg.pop_back();
		} else {
			while (taken[cur]) {
				cur--;
			}
			ans[i] = cur;
			taken[cur] = true;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		vector<int> res = solve();
		if (res.empty()) {
			cout << -1 << endl;
		} else {
			for (int val : res) {
				cout << val << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
