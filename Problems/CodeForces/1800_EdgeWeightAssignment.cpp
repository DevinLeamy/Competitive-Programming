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



int diff;
bool dfs(int cur, int last, int dist, vector<vector<int>>& adj, bool isRoot) {
	if (dist % 2 == 0 && adj[cur].size() == 1 && !isRoot) return true;
	else if (dist % 2 == 1 && adj[cur].size() == 1 && !isRoot) return false;
	bool good = true;
	for (int i = 0; i < adj[cur].size(); i++) {
		int node = adj[cur][i];
		if (node == last) continue;
		if (!dfs(node, cur, dist + 1, adj, false)) {
			good = false;
		}
	}
	return good;
}

void isLeaf(int cur, int last, vector<vector<int>>& adj) {
	int count = 0;
	for (int i = 0; i < adj[cur].size(); i++) {
		int node = adj[cur][i];
		if (adj[node].size() == 1) count++;
		if (node != last) isLeaf(node, cur, adj);
	}
	if (count > 1) {
		diff -= count-1;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	diff = n-1;
	bool allEven = true;
	vector<vector<int>> adj(n+1);
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 0; i <= n; i++) {
		if (adj[i].size() == 1) {
			allEven = dfs(i, -1, 0, adj, true);
			isLeaf(i, -1, adj);
			break;
		}
	}
	int min = allEven? 1 : 3;
	int max = diff;
	cout << min << " " << max << endl;
	return 0;
}
