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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, m; cin >> n >> m;
	vector<vector<int> > adj(n + 1, vector<int>());
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vector<int> vis(n + 1, -1);
	queue<PI> q;
	q.push(make_pair(1, -2));
	while (!q.empty()) {
		PI cur = q.front(); q.pop();
		int node = cur.first;
		int prev = cur.second;
		if (vis[node] != -1)
			continue;
		vis[node] = prev;
		if (node == n) {
			break;
		}
		for (int next : adj[node]) {
			if (vis[next] != -1)
				continue;
			q.push(make_pair(next, node));
		}
	}
	if (vis[n] == -1) {
		cout << "IMPOSSIBLE\n";
	} else {
		vector<int> ans;
		int cur = n;
		while (vis[cur] != -2) {
			ans.pb(cur);
			cur = vis[cur];
		}
		ans.pb(1);
		cout << ans.size() << "\n";
		for (int i = (int) ans.size() - 1; i >= 0; i--) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
