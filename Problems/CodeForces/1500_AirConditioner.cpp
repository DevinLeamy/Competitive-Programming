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
		int n; ll m; cin >> n >> m;
		vector<vector<ll>> cus;
		cus.pb({0, m, m});
		for (int i = 0; i < n; i++) {
			ll t, l, h; cin >> t >> l >> h;
			cus.pb({t, h, l});
		}
		bool found = false;
		for (int i = 0; i <= n; i++) {
			vector<ll> cur = cus[i];
			for (int j = i+1; j <= n; j++) {
				vector<ll> nxt = cus[j];
				ll t_diff = nxt[0] - cur[0];
				if (nxt[2] > cur[1] && nxt[2] - cur[1] > t_diff) found = true;
				if (cur[2] > nxt[1] && cur[2] - nxt[1] > t_diff) found = true;
			}
		}
		if (found) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
