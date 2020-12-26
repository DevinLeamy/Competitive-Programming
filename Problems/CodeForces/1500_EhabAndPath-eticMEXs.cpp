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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<vector<int>> adj(n);
	vector<bool> is_leaf(n, true);
	vector<PI> edges;
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
		edges.pb({u, v});
		if (adj[u].size() > 1) is_leaf[u] = false;
		if (adj[v].size() > 1) is_leaf[v] = false;
	}
	int cur = 0;
	vector<int> ans(n-1, -1);
	for (int i = 0; i < n-1; i++) {
		PI edge = edges[i];
		if (is_leaf[edge.first] || is_leaf[edge.second]) {
			ans[i] = cur;
			cur++;
		}
	}
	for (int val : ans) {
		if (val == -1) {
			printf("%i\n", cur);
			cur++;
		} else {
			printf("%i\n", val);
		}
	}
	return 0;
}
