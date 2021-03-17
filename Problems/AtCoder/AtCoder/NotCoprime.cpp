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

ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> vals(n);
	vector<ll> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	
	ll ans = LINF;
	for (int i = 1; i <= (1 << 15); i++) {
		ll cur = 1;
		bool bad = false;
		for (int j = 0; j < 15; j++) {
			if (1 & (i >> j))
				cur *= primes[j];
		}
		for (int val : vals) {
			if (gcd(val, cur) == 1)
				bad = true;
		}
		if (bad)
			continue;
		ans = min(ans, cur);
	}
	cout << ans << endl;
	return 0;
}
