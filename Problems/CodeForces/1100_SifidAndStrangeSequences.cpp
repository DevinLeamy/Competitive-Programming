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
#define view2(a, b) cout << "DEBUG: " << a << " " << b << endl;
using namespace std;
char _;

int solve() {
	int n; cin >> n;
	vector<ll> negs;
	ll min_pos = LINF;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		if (a < min_pos && a > 0) {
			min_pos = a;
		}
		if (a <= 0) {
			negs.pb(a);
		}
	}
	sort(negs.begin(), negs.end());
	int cnt = (int) negs.size();
	if (cnt == 0) {
		return 1;
	}
	if (cnt == 1) {
		return min(n, 2);
	}
	ll sml = LINF;
	for (int i = 0; i < negs.size() - 1; i++) {
		sml = min(sml, abs(negs[i] - negs[i + 1]));
	}
	if (sml >= min_pos)
		return cnt + 1;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		cout << solve() << endl;
	}
	return 0;
}
