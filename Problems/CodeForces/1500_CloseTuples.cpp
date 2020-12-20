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

ll fact(ll n) {
	if (n == 0) return 1;
	return n * fact(n-1);
}

ll nCr(ll n, ll r) {
	if (r > n) return 0ll;
	ll x = 1;
	for (int i = (int) n-r+1; i <= n; i++) x *= i;
	return x/fact(r);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n, a; cin >> n;
		vector<int> vals(n+4);
		for (int i = 0; i < n; i++) {
			cin >> a; vals[a]++;
		}
		ll ans = 0;
		for (int i = 0; i <= n; i++) {
			ans += nCr(vals[i], 3);
			ans += vals[i] * nCr(vals[i+1], 2);
			ans += vals[i] * nCr(vals[i+2], 2);
			ans += vals[i] * vals[i+1] * vals[i+2];
			ans += nCr(vals[i], 2) * vals[i+1];
			ans += nCr(vals[i], 2) * vals[i+2];
		}
		cout << ans << endl;
	}
	return 0;
}
