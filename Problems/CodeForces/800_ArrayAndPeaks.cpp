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
	int n, k; cin >> n >> k;
	if (k == 0) {
		vector<int> ans(n);
		for (int i = 1; i <= n; i++)
			ans[i - 1] = i;
		return ans;
	}
	
	if (k == 1 && n < 3)
		return {};
	if (k - 1 > (n - 3) / 2)
		return {};
	vector<int> ans(n, -1);
	ans[0] = 1;
	int cur = 3;
	int cnt = 0;
	for (int i = 1; i < n; i += 2) {
		ans[i] = cur;
		if (i == n - 1)
			return {};
		ans[i + 1] = cur - 1;
		cur += 2;
		cnt++;
		if (cnt == k)
			break;
	}
	cur--;
	for (int i = 0; i < n; i++) {
		if (ans[i] == -1) {
			ans[i] = cur;
			cur++;
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
			for (int val : res)
				cout << val << " ";
			cout << endl;
		}
	}
	return 0;
}
