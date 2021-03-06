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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	ll ans = 0;
	vector<int> vals(n);
	for (int i = 0; i < n; i++) { cin >> vals[i]; }
	for (int i = 0; i < 31; i++) {
		ll best = 0;
		ll cur = 0;
		for (int j = 0; j < n; j++) {
			cur += vals[j] > i? -INF: vals[j];
			best = max(cur - i, best);
			if (cur < 0) {
				cur = 0;
			}
		}
		ans = max(ans, best);
	}
	cout << ans << endl;
	return 0;
}
