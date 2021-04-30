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
	vector<vector<int> > adj(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vector<int> team(n + 1);
	for (int i = 1; i <= n; i++) {
		if (team[i] != 0)
			continue;
		queue<PI> cur;
		cur.push({i, 1});
		while (!cur.empty()) {
			PI val = cur.front(); cur.pop();
			team[val.first] = val.second;
			int new_v = (val.second == 1)? 2 : 1;
			for (int fri : adj[val.first]) {
				if (team[fri] == 0) {
					cur.push({fri, new_v});
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int fri : adj[i]) {
			if (team[fri] == team[i]) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << team[i] << " ";
	}
	cout << "\n";
	return 0;
}
