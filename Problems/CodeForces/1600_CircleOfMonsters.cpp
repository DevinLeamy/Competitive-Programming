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
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		vector<PL> vals(n);
		for (int i = 0; i < n; i++) cin >> vals[i].first >> vals[i].second;
		
		ll ans = max(0ll, vals[0].first - vals[n-1].second);
		ll min = std::min(vals[n-1].second, vals[0].first);
		for (int i = 1; i < n; i++) {
			ans += std::max(0ll, vals[i].first - vals[i-1].second);
			min = std::min(min, std::min(vals[i-1].second, vals[i].first));
		}
		ans += min;
		
		printf("%lld\n", ans);
	}
	return 0;
}
