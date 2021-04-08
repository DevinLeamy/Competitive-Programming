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

int a[200005];
ll dp[200005];
ll dp2[200005];
ll ans[200005];
vector<vector<int>> adj(200005, vector<int>());

void dfs(int v, int l = -1) {
	ll sum = 0;
	ll sum2 = a[v]; // Subtree sum
	for (int node : adj[v]) {
		if (node == l)
			continue;
		dfs(node, v);
		sum2 += dp2[node];
		sum += dp[node] + dp2[node];
	}

	dp[v] = sum;
	dp2[v] = sum2;
}

void dfs2(int v, int l = -1) {
	ans[v] = dp[v];
	for (int node : adj[v]) {
		if (node == l)
			continue;
		dp[v] -= dp[node] + dp2[node];
		dp2[v] -= dp2[node];
		dp2[node] += dp2[v];
		dp[node] += dp[v] + dp2[v];
	
		dfs2(node, v);
		
		dp[node] -= dp[v] + dp2[v];
		dp2[node] -= dp2[v];
		dp2[v] += dp2[node];
		dp[v] += dp[node] + dp2[node];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0);
	dfs2(0);
	ll max = 0;
	for (int i = 0; i < n; i++)
		max = std::max(max, ans[i]);
		
	cout << max << "\n";
	
	return 0;
}
