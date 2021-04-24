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
	int n; ll k; cin >> n >> k;
	if (n <= 63 && k > (ll) pow(2ll, n - 1))
		return {};
	
	vector<bool> set(n + 5);
	ll rem = k - 1;
	for (int i = 0; i < 64; i++) {
		if (rem & 1)
			set[i + 1] = true;
		rem /= 2ll;
	}
	queue<int> vals;
	vector<int> ans(n);
	int cur = 1;
	int ans_idx = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (set[i]) {
			vals.push(cur);
		} else {
			int idx = ans_idx;
			while (!vals.empty()) {
				ans[idx] = vals.front(); vals.pop();
				idx--;
			}
			ans[idx] = cur;
		}
		ans_idx++;
		cur++;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		vector<int> ans = solve();
		if (ans.empty()) {
			cout << -1 << "\n";
		} else {
			for (int val : ans)
				cout << val << " ";
			cout << "\n";
		}
	}
	return 0;
}
