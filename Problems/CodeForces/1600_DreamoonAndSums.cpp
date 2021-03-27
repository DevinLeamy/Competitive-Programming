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

ll mod =  1000000007ll;
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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	ll a, b; cin >> a >> b;
	ll ans = 0;
	ll prod = divide(mult(b, b - 1), 2);
	for (ll i = 1; i <= a; i++) {
		ans = add(ans, mult(mult(i, b) + 1, prod));
	}
	cout << ans << endl;
	return 0;
}
