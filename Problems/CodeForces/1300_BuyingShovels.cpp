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
	int t; cin >> t;
	loop(t) {
		ll n, k; cin >> n >> k;
		if (k >= n) { cout << "1" << endl; continue; }
		ll ans = n;
		for (ll i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				if (i <= k) { ans = min(ans, n / i); }
				if (n / i <= k) { ans = min(ans, i); }
			}
		}
		cout << ans << endl;
	}
	return 0;
}
