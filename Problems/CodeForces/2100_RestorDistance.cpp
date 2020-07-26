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

vector<ll> vals(100000);
ll n, a, r, m;
ll cost(ll high) {
	ll above = 0;
	ll below = 0;
	for (int i = 0; i < n; i++) {
		if (vals[i] > high) {
			above += vals[i] - high;
		} else if (vals[i] < high) {
			below += high - vals[i];
		}
	}
	if (m < a + r) {
		return (min(above, below) * m) + ((above - min(above, below)) * r) + ((below - min(above, below)) * a);
	} else {
		return above * r + below * a;
	}
}
ll ternarySearch(ll low, ll high) {
	while (high - low > 3) {
		ll mid1 = low + (high - low)/3;
		ll mid2 = high - (high - low)/3;
		ll cost1 = cost(mid1);
		ll cost2 = cost(mid2);
		if (cost1 > cost2) {
			low = mid1;
		} else {
			high = mid2;
		}
	}
	return low;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> a >> r >> m;
	for (int i = 0; i < n; i++) { cin >> vals[i]; }
	ll low = ternarySearch(0ll, 1000000000ll);
	cout << min( min( cost(low), cost(low + 1) ), min( cost(low + 2), cost(low + 3) ) ) << endl;
	return 0;
}
