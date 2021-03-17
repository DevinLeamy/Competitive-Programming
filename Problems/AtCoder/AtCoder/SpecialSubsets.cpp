#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <iomanip>
#define INF 2147483647
#define LINF 9223372036854775807ll
#define PI pair<int, int>
#define PL pair<long long, long long>
#define ll long long
#define pb push_back
#define loop(h) while(h--)
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;
char _;


ll mod = 998244353ll;

ll binexp(ll a, ll b) {
	ll res = 1;
	if (a <= 0) return 1;
	while(b > 0) {
		if (b % 2 == 1) res *= a;
		a *= a;
		a %= mod;
		res %= mod;
		b /= 2;
	}
	return res;
}

ll cycle_cnt = 0;

void label_cycle(int cur, queue<int> &prev, vector<int> &adj, vector<bool> &vis, vector<bool> &in_cycle) {
	if (in_cycle[cur])
		return;
	
	if (vis[cur]) {
		cycle_cnt++;
		while (!prev.empty()) {
			in_cycle[prev.front()] = true;
			prev.pop();
		}
	} else {
		vis[cur] = true;
		prev.push(cur);
		label_cycle(adj[cur], prev, adj, vis, in_cycle);
		in_cycle[cur] = true; // Even if it doesn't form a cycle, we can treat it like it does
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> adj(n);
	vector<bool> in_cycle(n), vis(n);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		a--;
		adj[i] = a;
	}
	for (int i = 0; i < n; i++) {
		queue<int> prev;
		label_cycle(i, prev, adj, vis, in_cycle);
	}
	
	ll ans = binexp(2, cycle_cnt) - 1;
	cout << ans % mod << endl;
	
	return 0;
}
