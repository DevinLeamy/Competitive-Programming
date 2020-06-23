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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		ll n, m, x, l, r; cin >> n >> x >> m;
		ll lp = x;
		ll rp = x;
		for (int i = 0; i < m; i++) {
			cin >> l >> r;
			if (l <= lp && r >= lp) {
				rp = max(rp, r);
				lp = min(lp, l);
			} else if (r >= rp && l <= rp) {
				rp = max(rp, r);
				lp = min(lp, l);
			}
		}
		cout << rp - lp + 1 << endl;
		
	}
	return 0;
}
