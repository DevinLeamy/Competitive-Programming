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

void dfs(int cur, int last, vector<vector<int>> &adj, vector<PL> &dp, vector<PL> &vals) {
	PL maxes = {0, 0};
	for (int node : adj[cur]) {
		if (node == last)
			continue;
		dfs(node, cur, adj, dp, vals);
		maxes.first += max(abs(vals[cur].first - vals[node].first) + dp[node].first,
						   abs(vals[cur].first - vals[node].second) + dp[node].second);
		maxes.second += max(abs(vals[cur].second - vals[node].first) + dp[node].first,
							abs(vals[cur].second - vals[node].second) + dp[node].second);
	}
	dp[cur] = maxes;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		vector<PL> vals(n);
		for (int i = 0; i < n; i++)
			cin >> vals[i].first >> vals[i].second;
		vector<vector<int>> adj(n);
		for (int i = 0; i < n - 1; i++) {
			int a, b; cin >> a >> b;
			a--; b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		vector<PL> dp(n);
		int start = 0;
		for (int i = 0; i < n; i++) {
			if ((int) adj[i].size() == 1) {
				start = i;
				break;
			}
		}
		dfs(start, -1, adj, dp, vals);
		cout << max(dp[start].first, dp[start].second) << endl;
	}
	return 0;
}
