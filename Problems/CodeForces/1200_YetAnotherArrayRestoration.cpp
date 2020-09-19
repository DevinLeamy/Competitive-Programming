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
		int n, x, y; cin >> n >> x >> y;
		int diff = y - x;
		int minTop = INF;
		vector<int> ans;
		if (n == 2) {
			cout << x << " " << y << endl;
			continue;
		}
		for (int i = 1; i <= diff; i++) {
			int placed = 2;
			int x1 = x;
			vector<int> vals;
			vals.pb(x);
			vals.pb(y);
			if (diff % i == 0) {
				while (x1 != y) {
					x1 += i;
					if (x1 != y) {
						vals.pb(x1);
						placed++;
					}
				}
				x1 = x;
				if (placed > n) {
					continue;
				}
				while (x1 > 0 && placed != n) {
					x1 -= i;
					if (x1 <= 0) break;
					vals.pb(x1);
					placed++;
				}
				int y1 = y;
				while (placed != n) {
					y1 += i;
					vals.pb(y1);
					placed++;
				}
				sort(vals.begin(), vals.end());
				if (vals[n-1] < minTop) {
					minTop = vals[n-1];
					ans = vals;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
