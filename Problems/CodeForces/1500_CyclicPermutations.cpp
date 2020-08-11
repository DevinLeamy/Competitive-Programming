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

ll mod = 1000000007;
ll fact(ll n) {
	ll res = 1;
	for (int i = 1; i <= n; i++) {
		res *= i;
		res %= mod;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	ll a = 1;
	for (int i = 0; i < n-1; i++) {
		a *= 2;
		a %= mod;
	}
	ll ans = (fact(n) + mod - a) % mod;
	cout << ans << endl;
	return 0;
}
