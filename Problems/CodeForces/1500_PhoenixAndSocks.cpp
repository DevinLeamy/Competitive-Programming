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

int solve() {
	int n, l, r; cin >> n >> l >> r;
	vector<PI> cnts(n + 1);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (i < l) {
			cnts[a].first++;
		} else {
			cnts[a].second++;
		}
	}
	int l_r = 0;
	int r_r = 0;
	for (int i = 0; i <= n; i++) {
		int rem = min(cnts[i].first, cnts[i].second);
		cnts[i].first -= rem;
		cnts[i].second -= rem;
		if (cnts[i].first == 0) {
			rem = cnts[i].second;
		} else if (cnts[i].second == 0) {
			rem = cnts[i].first;
		}
		l_r += cnts[i].first % 2;
		r_r += cnts[i].second % 2;
		cnts[i].first -= cnts[i].first % 2;
		cnts[i].second -= cnts[i].second % 2;
	}
	// Pair off left with diff color right
	int rem = min(l_r, r_r);
	ans += rem;
	l_r -= rem;
	r_r -= rem;
	for (int i = 0; i <= n; i++) {
		if (r_r == 0) {
			int take = min(l_r - l_r % 2, cnts[i].second);
			ans += take;
			l_r -= take;
			cnts[i].second -= take;
		} else {
			int take = min(r_r - r_r % 2, cnts[i].first);
			ans += take;
			r_r -= take;
			cnts[i].first -= take;
		}
		ans += cnts[i].first / 2 + cnts[i].second / 2;
	}
	ans += l_r + r_r;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		printf("%d\n", solve());
	}
	return 0;
}
