#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
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
using namespace std;
char _;

long double ans = 0;
void dfs(int cur, int last, ll depth, long double pro, vector<vector<int>>& adj) {
	long double paths = adj[cur].size();
	if (last != -1) paths--;
	if (paths == 0) ans += (pro/1000000.0L) * (double)depth;
	for (int node : adj[cur]) {
		if (node == last) continue;
		dfs(node, cur, depth + 1, pro / paths, adj);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<vector<int>> adj(n+1);
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, -1, 0, 1000000.0L, adj);
	cout << ans << endl;
	return 0;
}
