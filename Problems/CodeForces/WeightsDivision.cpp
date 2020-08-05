#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
//#include <multiset>
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

ll cost = 0;
vector<PL> weights;
int dfs(int cur, int last, vector<vector<pair<int, ll>>> &adj) {
	int count = 0;
	for (int i = 0; i < adj[cur].size(); i++) {
		int node = adj[cur][i].first;
		ll weight = adj[cur][i].second;
		if (node != last) {
			int after = dfs(node, cur, adj);
			count += after;
			weights.pb({weight, after});
			cost += weight * after;
		}
	}
	if (count == 0) return 1;
	return count;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n; ll s; cin >> n >> s;
		vector<vector<pair<int, ll>>> adj(n);
		ll max = 0;
		for (int i = 0; i < n-1; i++) {
			int a, b; ll w; cin >> a >> b >> w;
			a--; b--;
			adj[a].pb({b, w});
			adj[b].pb({a, w});
			max = std::max(max, (ll) w);
		}
		cost = 0;
		weights.clear();
		dfs(0, -1, adj);
		multiset<pair<ll, PL>> costs;
		for (int i = 0; i < weights.size(); i++) {
			ll gain = (weights[i].first - weights[i].first/2) * weights[i].second;
			costs.insert({gain, weights[i]});
		}
		int moves = 0;
		for (auto iter = costs.rbegin(); iter != costs.rend(); iter++) {
			pair<ll, PL> val = *iter;
			if (cost <= s) break;
			ll gain = val.first;
			ll weight = val.second.first;
			ll count = val.second.second;
			moves++;
			cost -= gain;
			weight /= 2;
			ll newGain = (weight - weight/2) * count;
			costs.insert({newGain, {weight, count}});
		}
		cout << moves << endl;
	}
	return 0;
}
