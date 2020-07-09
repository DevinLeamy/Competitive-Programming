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

vector<pair<ll, int>> vals;

bool works(int start, int end) {
	if ((vals[end-1].first - vals[start].first) % (end - start - 1) != 0) return false;
	ll diff = (vals[end-1].first - vals[start].first) / (end - start - 1);
	for (int i = start; i < end; i++) {
		if (vals[i].first != vals[start].first + (diff * (i - start))) {
			return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	ll a;
	for (int i = 0; i < n; i++) { cin >> a; vals.pb({a, i + 1}); }
	if (n == 2 || n == 3) {
		cout << 1;
		return 0;
	}
	sort(vals.begin(), vals.end());
	if (works(1, n)) {
		cout << vals[0].second;
	} else if (works(0, n-1)) {
		cout << vals[n-1].second;
	} else {
		ll diff = (vals[n-1].first - vals[0].first) / (n - 2);
		vector<int> bad;
		for (int i = 0; i < n; i++) {
			if (vals[i].first != vals[0].first + (diff * (i - bad.size()))) {
				bad.pb(vals[i].second);
			}
		}
		if (bad.size() > 1) {
			cout << -1;
		} else {
			cout << bad[0];
		}
	}
	return 0;
}
