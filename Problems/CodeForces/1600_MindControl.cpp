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
		int n, m, k; cin >> n >> m >> k;
		vector<ll> vals(n);
		for (int i = 0; i < n; i++) cin >> vals[i];
		
		int un_ctrl = max(0, m - k - 1);
		int ctrl = min(m - 1, k);
		vector<ll> bests(ctrl + 1, LINF);
		for (int i = 0; i <= un_ctrl; i++) {
			int lp = i;
			int rp = n - 1 - (un_ctrl - i);
			for (int j = 0; j <= ctrl; j++) {
				ll first = vals[lp + j];
				ll last = vals[rp - (ctrl - j)];
				bests[j] = min(bests[j], max(first, last));
			}
		}
		ll ans = 0;
		for (ll val : bests) ans = max(ans, val);
		printf("%lld\n", ans);
	}
	return 0;
}
