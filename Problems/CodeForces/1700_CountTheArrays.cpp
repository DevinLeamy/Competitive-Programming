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

ll mod = 998244353ll;
ll fact(ll n) {
	ll res = 1;
	for (ll i = 1; i <= n; i++) {
		res *= i;
		res %= mod;
	}
	return res;
}
ll pow_(ll n, ll r) {
	ll res = 1;
	if (n <= 0) return 1;
	while(r > 0) {
		if (r % 2 == 1) res *= n;
		n *= n;
		n %= mod;
		res %= mod;
		r /= 2;
	}
	return res;
}
ll mult(ll a, ll b) {
	return (a * b) % mod;
}

ll divide(ll a, ll b) {
	return mult(a, pow_(b, mod-2));
}

ll comb(ll n, ll r) {
	ll top = fact(n);
	ll bottom = (fact(n-r) * fact(r)) % mod;
	return divide(top, bottom);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m; cin >> n >> m;
	ll x = comb(m, n-1);
	ll p = pow_(2, n-3);
	cout << mult(p, mult(x, n-2)) << endl;
	return 0;
}
