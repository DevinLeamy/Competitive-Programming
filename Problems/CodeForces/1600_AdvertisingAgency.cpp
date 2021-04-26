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
#define view2(a, b) cout << "DEBUG: " << a << " " << b << endl;
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

ll solve() {
	int n, k; cin >> n >> k;
	vector<int> vals(n);
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	
	sort(vals.rbegin(), vals.rend());
	ll last_group = vals[k - 1];
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (vals[i] == last_group)? 1 : 0;
	int taken = 0;
	for (int i = 0; i < k; i++)
		taken += (vals[i] == last_group)? 1 : 0;
	return nCr(cnt, taken);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		printf("%lld\n", solve());
	}
	return 0;
}
