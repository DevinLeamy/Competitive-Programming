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

vector<vector<int>> adj(200005, vector<int>());
vector<int> dp(200005);
vector<int> ans(200005);
int white[200005];

void dfs(int cur, int last = -1) {
	dp[cur] = white[cur];
	for (int node : adj[cur]) {
		if (node == last)
			continue;
		dfs(node, cur);
		dp[cur] += max(0, dp[node]);
	}
}

void dfs2(int cur, int last = -1) {
	ans[cur] = dp[cur];
	for (int node : adj[cur]) {
		if (node == last)
			continue;
		dp[cur] -= max(0, dp[node]);
		dp[node] += max(0, dp[cur]);
		dfs2(node, cur);
		dp[node] -= max(0, dp[cur]);
		dp[cur] += max(0, dp[node]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		white[i] = (a == 1)? 1 : -1;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		--a; --b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0);
	dfs2(0);
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
