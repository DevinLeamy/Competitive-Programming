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
	int n; cin >> n;
	vector<ll> vals(n);
	for (int i = 0; i < n; i++) cin >> vals[i];
	
	ll best = 0;
	int idx = -1;
	vector<ll> output;
	for (int i = 0; i < n; i++) {
		ll last = vals[i];
		ll cnt = vals[i];
		vector<ll> new_output;
		for (int j = i-1; j >= 0; j--) {
			ll floors = min(last, vals[j]);
			cnt += floors;
			last = floors;
			new_output.pb(floors);
		}
		reverse(new_output.begin(), new_output.end());
		new_output.pb(vals[i]);
		
		last = vals[i];
		for (int j = i+1; j < n; j++) {
			ll floors = min(last, vals[j]);
			cnt += floors;
			last = floors;
			new_output.pb(floors);
		}
		if (cnt > best) {
			best = cnt;
			idx = i;
			swap(output, new_output);
		}
	}
	
	for (ll floors : output) printf("%lld ", floors);
	return 0;
}
