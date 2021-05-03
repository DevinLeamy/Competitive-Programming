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
	int n, x; cin >> n >> x;
	int cur = 0;
	vector<bool> taken(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++)
		cin >> weights[i];
	sort(weights.begin(), weights.end());
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (cur + weights[i] == x)
			continue;
		cur += weights[i];
		taken[i] = true;
		ans.pb(weights[i]);
	}
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			ans.pb(weights[i]);
			if (cur + weights[i] == x)
				return {};
		}
	}
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
			cout << "\n";
		}
	}
	return 0;
}
