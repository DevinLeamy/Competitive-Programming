#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
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
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;
char _;

ll mod = 998244353ll;
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

ll facts[250001];
ll fact(ll n) {
	if (n == 0 || n == 1)
		return 1ll;
	if (facts[n] != 0)
		return facts[n];
	facts[n] = mult(n, fact(n - 1));
	return facts[n];
}

ll nCr(int n, int r) {
	if (r > n) return 0;
	return divide(fact(n), mult(fact(r), fact(n - r)));
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<ll> cnt(n);
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			cnt[i - 1] = 10;
			continue;
		}
		ll total = n - i + 1;
		ll no_sides = max(0ll, total - 2);
		no_sides = mult(10, no_sides);
		no_sides = mult(81, no_sides);
		no_sides = mult(binexp(10, n - i - 2), no_sides);
		ll sides = total - max(0ll, total - 2);
		sides = mult(10, sides);
		sides = mult(9, sides);
		sides = mult(binexp(10, n - i - 1), sides);
		cnt[i - 1] = add(sides, no_sides);
	}
	
	for (ll val : cnt)
		cout << val << " ";
	cout << endl;
	return 0;
}
