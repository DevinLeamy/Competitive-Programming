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
		vector<ll> vals(n);
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
		}
		vector<bool> vis(n);
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ll cur = 0;
			ll idx = i;
			while (idx < n) {
				if (vis[idx]) break;
				vis[idx] = true;
				cur += vals[idx];
				idx += vals[idx];
			}
			ans = max(cur, ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
