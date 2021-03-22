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
	int n, m; cin >> n >> m;
	int cap = m / 2 + m % 2;
	vector<vector<int> > days(m, vector<int>());
	vector<int> cntr(n + 1);
	vector<int> empty;
	for (int i = 0; i < m; i++) {
		int cnt; cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int a; cin >> a;
			days[i].pb(a);
		}
		if (cnt == 1)
			cntr[days[i][0]]++;
	}
	for (int i = 0; i <= n; i++) {
		if (cntr[i] > cap) {
			return empty;
		}
	}
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		if (days[i].size() == 1) {
			ans.pb(days[i][0]);
			continue;
		}
		bool found = false;
		for (int j = 0; j < days[i].size(); j++) {
			int val = days[i][j];
			if (cntr[val] < cap) {
				cntr[val]++;
				ans.pb(val);
				found = true;
				break;
			}
		}
		if (!found)
			return empty;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		vector<int> res = solve();
		if (res.empty())
			cout << "NO\n";
		else {
			cout << "YES\n";
			for (int val : res)
				cout << val << " ";
			cout << endl;
		}
	}
	return 0;
}
