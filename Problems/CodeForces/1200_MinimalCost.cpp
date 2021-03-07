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
	int cols = 1000002;
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		ll u, v; cin >> u >> v;
		// +u down, +v side
		vector<int> vals(n);
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
		}
		
		int last = vals[0];
		bool blocked = true;
		bool line = true;
		ll cost = 0;
		int pos = vals[0] - 1;
		for (int i = 1; i < n; i++) {
			int cur = vals[i];
			if (abs(cur - last) > 1) {
				blocked = false;
				pos = cols;
			} else {
				pos = cur - 1;
			}
			if (cur - last != 0) line = false;
			if (pos == 0 && cur == 0) {
				if (line) {
					cost += v + min(u, v);
				} else if (blocked) {
					cost += min(u, v);
				}
				blocked = true;
				line = true;
				pos = cols - 1;
			}
			last = cur;
		}
		if (line) {
			cost += v + min(u, v);
		} else if (blocked) {
			cost += min(u, v);
		}
		cout << cost << endl;
		
	}
	return 0;
}
