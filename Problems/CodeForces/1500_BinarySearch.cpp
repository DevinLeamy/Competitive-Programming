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
ll divide(ll a, ll b) {
	return mult(a, binexp(b, mod-2)) % mod;
}

ll fact(ll n) {
	if (n <= 0) return 1;
	ll res = 1;
	while (n > 0) {
		res *= n;
		n--;
		res %= mod;
	}
	return res;
}

ll nCr(int n, int r) {
	if (r > n) return 0;
	return divide(fact(n), mult(fact(r), fact(n - r)));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, x, pos; cin >> n >> x >> pos;
	int left = 0;
	int right = n;
	int rem = n-1;
	int less = 0;
	int greater = 0;
	ll cost = 1;
	while (left < right) {
		int middle = (left + right)/2;
		if (middle <= pos) {
			if (middle != pos) {
				less++;
			}
			left = middle + 1;
		} else {
			greater++;
			right = middle;
		}
	}
	rem -= greater + less;
	cost *= mult(nCr(n-x, greater),fact(greater));
	cost %= mod;
	cost *= mult(nCr(x-1, less), fact(less));
	cost %= mod;
	cost *= fact(rem);
	cost %= mod;
	cout << cost << endl;
	return 0;
}
