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
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;
char _;

ll mod = 1000000007ll;
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
ll divide(ll a, ll b) {
	return (a * binexp(b, mod-2)) % mod;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	string s; cin >> s;
	int k; cin >> k;
	int n = (int) s.length();
	ll ans = 0;
	ll two_n = binexp(2, n); // 2^n
	
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0' || s[i] == '5') {
			ll rem = i;
			ll numerator = binexp(two_n, k) - 1;
			ll denominator = two_n - 1;
			ll sum = divide(numerator, denominator);
			ans = (ans + (sum * binexp(2, rem) % mod)) % mod;
		}
	}
	cout << ans % mod << endl;
	return 0;
}
