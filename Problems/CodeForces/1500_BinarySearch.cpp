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

ll perm(ll n) {
	if (n == 0)
		return 1;
	ll res = 1;
	while (n != 1) {
		res *= n;
		res %= mod;
		n--;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int x, n, pos; cin >> n >> x >> pos;
	ll ans = 1;
	ll less = x - 1;
	ll more = n - x;
	
	ll left = 0;
	ll right = n;
	while (left < right) {
		ll middle = (left + right) / 2;
		if (middle == pos) {
			left = middle + 1;
		} else if (middle < pos) {
			left = middle + 1;
			ans *= less;
			less--;
		} else {
			right = middle;
			ans *= more;
			more--;
		}
		less = max(0ll, less);
		more = max(0ll, more);
		ans %= mod;
	}
	ans *= perm(less + more);
	ans %= mod;
	cout << ans << endl;
	return 0;
}
