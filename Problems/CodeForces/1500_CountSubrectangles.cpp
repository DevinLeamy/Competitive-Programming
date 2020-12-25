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
	int n, m; ll k; cin >> n >> m >> k;
	vector<bool> top(n);
	vector<bool> btm(m);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		top[i] = (a == 1);
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		btm[i] = (a == 1);
	}
	top.pb(false); btm.pb(false);
	vector<int> cnt_top(n+1), cnt_btm(m+1);
	int cur = 0;
	for (int i = 0; i <= n; i++) {
		if (top[i]) cur++;
		else {
			if (cur > 0) {
				cnt_top[cur]++;
				cur = 0;
			}
		}
	}
	
	cur = 0;
	for (int i = 0; i <= m; i++) {
		if (btm[i]) cur++;
		else {
			if (cur > 0) {
				cnt_btm[cur]++;
				cur = 0;
			}
		}
	}
	vector<PL> xs, ys;
	for (int i = 0; i <= n; i++) {
		if (cnt_top[i] > 0) xs.pb({i, cnt_top[i]});
	}
	for (int i = 0; i <= m; i++) {
		if (cnt_btm[i] > 0) ys.pb({i, cnt_btm[i]});
	}
	
	ll cnt = 0;
	for (PL pair_len : xs) {
		ll len = pair_len.first;
		for (PL pair_hgt : ys) {
			ll hgt = pair_hgt.first;
			if (len * hgt < k) continue;
			for (int i = 1; i <= sqrt(k); i++) {
				if (k % i != 0) continue;
				int x = i;
				int y = (int) k / i;
				cnt += max(0ll, (len - x + 1)) * max(0ll, (hgt - y + 1)) * pair_len.second * pair_hgt.second;
				if (x != y) {
					cnt += max(0ll, (len - y + 1)) * max(0ll, (hgt - x + 1)) * pair_len.second * pair_hgt.second;
				}
				
			}
		}
	}
	printf("%lld\n", cnt);
	return 0;
}
