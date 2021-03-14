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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, q; ll k; cin >> n >> q >> k;
	
	vector<ll> vals(n);
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}
	
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		l--; r--;
		ll first = vals[l] - 1;
		ll last = k - vals[r];
		ll gaps = (vals[r] - vals[l] + 1) - (r - l + 1);
		ll ans = first + last + 2 * gaps; // gaps can be filled by left or right element
		cout << ans << endl;
	}
	return 0;
}
