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

ll power(ll x, ll y) {
    if (y == 0)
        return 1;
    ll p = power(x, y / 2) % mod;
    p = (p * p) % mod;
    return (y % 2 == 0) ? p : (x * p) % mod;
}

ll mod_inverse(ll a) {
    return power(a, mod - 2);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	ll y = power(2, n);
	ll y_inv = mod_inverse(y);
	ll even = 1, odd = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) even = (even + odd) % mod;
		else odd = (odd + even) % mod;
	}
	if (n % 2 == 1) printf("%lld", (y_inv * even) % mod);
	else printf("%lld", (y_inv * odd) % mod);
	return 0;
}
