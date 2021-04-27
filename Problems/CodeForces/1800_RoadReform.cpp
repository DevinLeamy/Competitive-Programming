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

int n, m;
ll solve() {
	ll k;
	cin >> n >> m >> k;
	// Prims twice - One with larger than k roads, and the other without
	vector<vector<pair<ll, int>>> adj(n, vector<pair<ll, int>>());
	vector<ll> costs;
	for (int i = 0; i < m; i++) {
		int a, b; ll c;
		cin >> a >> b >> c;
		--a; --b;
		adj[a].pb({c, b});
		adj[b].pb({c, a});
		if (c > k) {
			costs.pb(c - k);
		}
	}
	sort(costs.begin(), costs.end());
	
	ll cost1 = 0; // Cost with above k cost edges
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	vector<bool> connected(n);
	connected[0] = true;
	for (auto edge : adj[0])
		q.push(make_pair(max(-1ll, edge.first - k), edge.second));
	bool found_over = false;
	for (int i = 0; i < n - 1; i++) {
		pair<ll, int> val = q.top(); q.pop();
		int node = val.second;
		if (connected[node]) {
			--i;
			continue;
		}
		if (val.first >= 0)
			found_over = true;
		cost1 += max(0ll, val.first);
		connected[node] = true;
		for (auto edge : adj[node])
			q.push(make_pair(max(-1ll, edge.first - k), edge.second));
	}
	if (!found_over) {
		if (costs.empty())
			cost1 = LINF; // Cannot build
		else
			cost1 = costs[0];
	}
	
	ll cost2 = LINF; // Cost without above k cost edges
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q2;
	for (int i = 0; i < n; i++)
		connected[i] = false;
	connected[0] = true;
	for (auto edge : adj[0]) {
		if (edge.first <= k)
			q2.push(make_pair(k - edge.first, edge.second));
	}
	for (int i = 0; i < n - 1; i++) {
		if (q2.empty()) {
			cost2 = LINF; // Cannot build
			break;
		}
		pair<ll, int> val = q2.top(); q2.pop();
		int node = val.second;
		if (connected[node]) {
			--i;
			continue;
		}
		cost2 = min(cost2, val.first);
		connected[node] = true;
		for (auto edge : adj[node])
			if (edge.first <= k)
				q2.push(make_pair(k - edge.first, edge.second));
	}
	
	return min(cost1, cost2);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		printf("%lld\n", solve());
	}
	return 0;
}
