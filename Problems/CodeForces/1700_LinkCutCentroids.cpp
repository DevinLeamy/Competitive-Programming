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

void dfs(int u, int prev, vector<int> &sz, vector<int> &centroid, const vector<vector<int>> &g, int n) {
	sz[u] = 1;
	bool is_centroid = true;
	for (auto v : g[u]) if (v != prev) {
		dfs(v, u, sz, centroid, g, n);
		sz[u] += sz[v];
		if (sz[v] > n / 2) is_centroid = false;
	}
	if (n - sz[u] > n / 2) is_centroid = false;
	if (is_centroid) centroid.push_back(u);
}

vector<int> get_centroids(const vector<vector<int>> &g) {
	int n = (int) g.size();
	vector<int> centroid;
	vector<int> sz(n);
	dfs(0, -1, sz, centroid, g, n);
	return centroid;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n, x, y; cin >> n;
		vector<vector<int>> adj(n);
		for (int i = 0; i < n-1; i++) {
			cin >> x >> y; x--; y--;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		vector<int> cnt = get_centroids(adj);
		if (cnt.size() == 1) {
			cout << cnt[0]+1 << " " << adj[cnt[0]][0]+1 << endl;
			cout << cnt[0]+1 << " " << adj[cnt[0]][0]+1 << endl;
		} else {
			for (int num : adj[cnt[0]]) {
				if (num != cnt[1]) {
					cout << cnt[0]+1 << " " << num+1 << endl;
					cout << num+1 << " " << cnt[1]+1 << endl;
					break;
				}
			}
		}
	}
	return 0;
}
