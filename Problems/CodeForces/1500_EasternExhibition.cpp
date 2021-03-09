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

ll solve() {
	int n; cin >> n;
	vector<ll> xs(n), ys(n);
	for (int i = 0; i < n; i++)
		cin >> xs[i] >> ys[i];
	
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	
	if (n % 2 == 1)
		return 1ll;
	ll x_pos = xs[n/2] - xs[n/2 - 1] + 1;
	ll y_pos = ys[n/2] - ys[n/2 - 1] + 1;
	return x_pos * y_pos;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		printf("%lld\n", solve());
	}
	return 0;
}
