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
void dfs(ll cur, ll pre, vector<vector<ll>> &adj, vector<ll> &c, vector<ll> &g, vector<ll> &p, vector<ll> &h) {
	ll hp = 0;
	for (ll loc : adj[cur]) {
		if (loc == pre) continue;
		dfs(loc, cur, adj, c, g, p, h);
		c[cur] += c[loc];
		hp += g[loc];
	}
	c[cur] += p[cur];
	g[cur] = (c[cur] + h[cur])/2;
	if (abs(c[cur] + h[cur])%2 == 1 || g[cur] > c[cur] || hp > g[cur] || g[cur] < 0) {
		works = false;
	}
	g[cur] = (c[cur] + h[cur])/2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n; ll m, a, b; cin >> n >> m;
		vector<ll> p(n);
		vector<ll> h(n);
		vector<vector<ll>> adj(n);
		vector<ll> c(n);
		vector<ll> g(n);
		for (int i = 0; i < n; i++) { cin >> p[i]; }
		for (int i = 0; i < n; i++) { cin >> h[i]; }
		for (int i = 0; i < n-1; i++) {
			cin >> a >> b; a--; b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		dfs(0, -1, adj, c, g, p, h);
		cout << (works? "YES":"NO") << endl;
		works = true;
		
	}
	return 0;
}
