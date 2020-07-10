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
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, q; cin >> n >> m >> q;
	ll gcd = ::gcd(n, m);
	loop(q) {
		ll s1, s2, e1, e2;
		cin >> s1 >> s2 >> e1 >> e2;
		s2--; e2--;
		ll cur1 = (s1 == 1)? s2 / (n/gcd): s2 / (m/gcd);
		ll cur2 = (e1 == 1)? e2 / (n/gcd): e2 / (m/gcd);
		if (cur1 == cur2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
