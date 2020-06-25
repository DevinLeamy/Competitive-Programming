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


ll func(ll n, ll v) {
	return n - n/v;
}

ll binarySearch(ll l, ll r, ll v, ll k) {
	if (l > r) { return r; }
	ll mid = (l + r)/2;
	if (func(mid, v) == k) { return mid; }
	if (func(mid, v) > k) { return binarySearch(l, mid-1, v, k); }
	else { return binarySearch(mid+1, r, v, k); }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		ll n, k; cin >> n >> k;
		if (n > k) { cout << k << endl; continue; }
		ll val = binarySearch(1, LINF, n, k);
		if (val % n == 0) { val--; }
		cout << val << endl;
	}
	return 0;
}
