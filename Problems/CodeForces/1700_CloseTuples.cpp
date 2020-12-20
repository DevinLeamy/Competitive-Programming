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

ll mod = 1000000007ll;
vector<ll> ft(200001);
ll mult(ll a, ll b) {
	return (a * b) % mod;
}

ll add(ll a, ll b) {
	return (a + b) % mod;
}

ll sub(ll a, ll b) {
	return (a + mod - b) % mod;
}

ll binexp(ll a, ll b) {
	ll res = 1;
	if (a <= 0) return 1;
	while(b > 0) {
		if (b % 2 == 1) res *= a;
		a *= a;
		a %= mod;
		res %= mod;
		b /= 2;
	}
	return res;
}
//Only works if mod is prime
ll divide(ll a, ll b) {
	return (a * binexp(b, mod-2)) % mod;
}

ll fact(ll n) {
	return ft[n];
}

ll nCr(int n, int r) {
	if (r > n) return 0;
	return divide(fact(n), mult(fact(r), fact(n - r)));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	ft[0] = 1;
	for (int i = 1; i < ft.size(); i++) {
		ft[i] = (i * ft[i-1]) % mod;
	}
	loop(t) {
		int n, m, k; cin >> n >> m >> k;
		vector<int> vals(n);
		for (int i = 0; i < n; i++) cin >> vals[i];
		sort(vals.begin(), vals.end());
		
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			int val = vals[i];
			int l = i;
			int r = (int) (upper_bound(vals.begin(), vals.end(), val + k) - vals.begin());
			int cnt = r - l;
			ans = add(ans, nCr(cnt-1, m-1));
		}
		cout << ans << endl;
		
	}
	return 0;
}
