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

bool works = true;
vector<bool> visited(1000000);
void dfs(int cur, int last, int llast, vector<vector<int>>& adj) {
	if (visited[cur]) return;
	visited[cur] = true;
	if (last != -1 && adj[cur].size() != adj[last].size()) works = false;
	bool valid = false;
	for (int i = 0; i < adj[cur].size(); i++) {
		int node = adj[cur][i];
		if (llast == node) valid = true;
		dfs(node, cur, last, adj);
	}
	if (!valid && llast != -1) works = false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n+1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, -1, -1, adj);
	}
	cout << (works? "YES" : "NO") << endl;
	return 0;
}
