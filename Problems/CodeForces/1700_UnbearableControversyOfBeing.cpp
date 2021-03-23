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
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, m; cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		--a; --b;
		adj[a].pb(b);
	}
	vector<vector<int> > cnts(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			for (int k = 0; k < adj[adj[i][j]].size(); k++) {
				if (adj[adj[i][j]][k] != i) {
					cnts[i][adj[adj[i][j]][k]]++;
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cnts[i][j] > 1) {
				ans += (cnts[i][j] * (cnts[i][j] - 1)) / 2;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
