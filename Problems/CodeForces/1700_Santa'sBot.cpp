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

ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

ll lcm(ll a, ll b) {
	return divide(mult(a, b), gcd(a, b));
}
int cnts[1000005];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<vector<int>> vals;
	
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		vals.pb(vector<int>(k));
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			vals[i][j] = a;
			cnts[a]++;
		}
	}
	ll x = 0, y = 1;
	for (int i = 0; i < n; i++) {
		ll cur_x = 0, cur_y = mult(mult(n, n), (int) vals[i].size());
		for (int val : vals[i])
			cur_x += cnts[val];

		ll new_y = y;
		if (y != cur_y) {
			new_y = lcm(y, cur_y);
			cur_x = mult(cur_x, divide(new_y, cur_y));
			if (new_y != y)
				x = mult(x, divide(new_y, y));
		}
		x = add(x, cur_x);
		y = new_y;
	}
	cout << mult(x, binexp(y, mod - 2));
	
	return 0;
}
