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

ll fits(ll top, ll k, int n) {
	return (k == 0 || top >= (ll) ceil(log2(k)) * (ll) n);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; ll p; cin >> n >> p;
	p *= 8;
	vector<ll> vals(n);
	for (int i = 0; i < n; i++) cin >> vals[i];
	sort(vals.begin(), vals.end());
	vector<int> cnts;
	ll cur = vals[0];
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (vals[i] == cur) cnt++;
		else {
			cnts.pb(cnt);
			cur = vals[i];
			cnt = 1;
		}
	}
	if (cnt > 0) cnts.pb(cnt);
	
	int max = 0;
	for (int i = 1; i <= cnts.size(); i++) {
		if (fits(p, i, n)) max = i;
	}
	cnt = 0;
	for (int i = 0; i < max; i++) cnt += cnts[i];
	
	int ans = n - cnt;
	for (int i = max; i < cnts.size(); i++) {
		cnt += cnts[i];
		cnt -= cnts[i - max];
		ans = min(ans, n - cnt);
	}
	printf("%d", ans);
	return 0;
}
