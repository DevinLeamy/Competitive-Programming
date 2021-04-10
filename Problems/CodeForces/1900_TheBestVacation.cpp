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

ll sum(ll a) {
	return (a * (a + 1)) / 2ll;
}

ll sum_range(ll a, ll b) {
	return sum(a) - sum(b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; ll x; cin >> n >> x;
	vector<ll> days(n);
	for (int i = 0; i < n; i++)
		cin >> days[i];
	vector<ll> presum_d(2*n + 1);
	vector<ll> presum_c(2*n + 1);
	presum_d.pb(0);
	presum_c.pb(0);
	for (int i = 0; i <= 2*n; i++) {
		presum_d[i + 1] = presum_d[i] + days[i % n];
		presum_c[i + 1] = presum_c[i] + sum(days[i % n]);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		// Start on last day
		ll start_day = presum_d[i + 1];
		ll end_day = start_day + (x - 1);
		int start_mon = (int) (lower_bound(presum_d.begin(), presum_d.end(), start_day + 1) - presum_d.begin());
		int end_mon = (int) (lower_bound(presum_d.begin(), presum_d.end(), end_day) - presum_d.begin());
		ll total = days[i]; // Last day
		total += presum_c[end_mon - 1] - presum_c[start_mon - 1]; // Month fully covered
		total += sum(end_day - presum_d[end_mon - 1]); // Trailing days
		ans = max(ans, total);
	}
	for (int i = n; i < 2*n; i++) {
		// End on last day
		ll end_day = presum_d[i + 1] - 1;
		ll start_day = end_day - (x - 1);
		int start_mon = (int) (lower_bound(presum_d.begin(), presum_d.end(), start_day) - presum_d.begin());
		int end_mon = (int) (lower_bound(presum_d.begin(), presum_d.end(), end_day) - presum_d.begin());
		ll total = 0; // Last day
		total += presum_c[end_mon] - presum_c[start_mon]; // Month fully covered
		total += sum_range(days[(start_mon - 1)%n], days[(start_mon - 1)%n] - (presum_d[start_mon] - start_day)); // Leading days
		ans = max(ans, total);
	}
	cout << ans << "\n";
	
	return 0;
}
