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

int MAXN = 300005;
vector<vector<bool>> vals(MAXN, vector<bool>(2));
vector<vector<int>> dp(MAXN, vector<int>(2));
vector<int> ans(MAXN);
int n;
void dfs(int cur, int t, int prev, int &vis) {
	if (cur < 0 || cur > n)
		return;
	if (dp[cur][t] != 0)
		return;
	vis++;
	if (cur != 0 && !vals[cur - 1][t]) {
		if (prev != cur - 1) {
			dfs(cur - 1, (t + 1) % 2, cur, vis);
		} else {
			vis++;
		}
	}
	if (vals[cur][t]) {
		if (prev != cur + 1) {
			dfs(cur + 1, (t + 1) % 2, cur, vis);
		} else {
			vis++;
		}
	}
	dp[cur][t] = vis;
}

void solve() {
	cin >> n;
	string s; cin >> s;
	for (int i = 0; i < n; i++) {
		vals[i][0] = s[i] == 'R';
		vals[i][1] = s[i] != 'R';
	}
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
		dp[i][1] = 0;
	}
	
	for (int i = 0; i <= n; i++) {
		int val = 0;
		dfs(i, 0, INF, val);
		ans[i] = dp[i][0] / 2 + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		solve();
		for (int i = 0; i <= n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
