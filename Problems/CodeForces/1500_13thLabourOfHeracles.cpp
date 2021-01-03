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
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		vector<ll> vals(n);
		for (int i = 0; i < n; i++) cin >> vals[i];
		
		vector<vector<int>> adj(n);
		for (int i = 0; i < n-1; i++) {
			int u, v; cin >> u >> v; u--; v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		vector<pair<ll, int>> not_leafs;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += vals[i];
			if (adj[i].size() > 1)
				not_leafs.pb({vals[i], (int) adj[i].size() - 1});
		}
		
		sort(not_leafs.begin(), not_leafs.end());
		
		int lp = (int) not_leafs.size() - 1;
		vector<ll> ans;
		ans.pb(sum);
		for (int i = 0; i < n - 2; i++) {
			if (ans.size() == n-1) break;
			while (not_leafs[lp].second == 0)
				lp--;
			sum += not_leafs[lp].first;
			not_leafs[lp].second--;
			ans.pb(sum);
		}
		for (ll val : ans) {
			printf("%lld ", val);
		}
		printf("\n");
		
	}
	return 0;
}
