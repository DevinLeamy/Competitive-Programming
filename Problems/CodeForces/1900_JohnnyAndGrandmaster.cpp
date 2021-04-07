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

int vals[1000005];
int MAXN = 1e6 + 5;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n, p; cin >> n >> p;
		for (int i = 0; i < n; i++)
			cin >> vals[i];
		sort(vals, vals + n);
		ll over = 0;
		bool reached_max = false;
		for (int i = n - 1; i >= 0; i--) {
			if (over > 0 || reached_max) {
				over = sub(over, 1);
			} else {
				over = 1;
			}
			if (i == 0)
				break;
			int inc = vals[i] - vals[i - 1];
			ll temp = over;
			over = mult(over, binexp(p, inc));
			if (!reached_max) {
				for (int j = 0; j < min(30, inc); j++) {
					temp *= p;
					if (temp >= MAXN) {
						reached_max = true;
						break;
					}
				}
			}
		}
		cout << mult(over, binexp(p, vals[0])) << endl;
	}
	return 0;
}
