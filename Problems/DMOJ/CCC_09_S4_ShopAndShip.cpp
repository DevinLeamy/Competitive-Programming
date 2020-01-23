#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define doH(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n, x, y, c, k, h, z, d; ll t; cin >> n >> t;
	ll pen[n]; fill(pen, pen + n, 9223372036854);
	vector <vector<pair<int, int>> > adj;
	doH(n) {adj.pb(vector<PI>());}
	for (int i = 0; i < t; i++) {
		cin >> x >> y >> c; x--; y--;
		adj[x].pb({c, y}); adj[y].pb({c, x});
	}
	cin >> k;
	doH(k) {
		cin >> h >> z; h--;
		pen[h] = z;
	}
	cin >> d; d--;
	while (true) {
		bool found = false;
		for (int i = 0; i < n; i++) {
			for (pair<int, int> value : adj[i]) {
				int loc = value.second; ll cost = value.first;
				if (pen[loc] + cost < pen[i]) {
					pen[i] = pen[loc] + cost;
					found = true;
				}
			}
		}
		if (!found) {break;}
	}
	cout << pen[d] << endl;
	return 0;
}
