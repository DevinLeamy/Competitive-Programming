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

vector<int> gain;
vector<vector<int>> adj(200000);
int dfs(int node, int last, int d) {
	int sum = 0;
	for (int a : adj[node]) {
		if (a != last) {
			if (adj[a].size() == 1) { sum += 1; gain.pb(0 - (d+1)); }
			else { sum += dfs(a, node, d + 1) + 1; }
		}
	}
	gain.pb(sum - d);
	return sum;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k, a, b; ll total = 0; cin >> n >> k;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, -1, 0);
	sort(gain.begin(), gain.end());
	reverse(gain.begin(), gain.end());
	for (int i = 0; i < n-k; i++) { total += gain[i]; }
	cout << total << endl;
	return 0;
}

