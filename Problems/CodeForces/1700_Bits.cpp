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


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll l, r; cin >> l >> r;
		if (l == r) {
			cout << l << endl;
			continue;
		}
		// Get largest bit that can be turn on
		ll ans = 0;
		int bits = 0;
		for (int i = 1; i < 64; i++) {
			ll cur = (1ll << i) - 1;
			cur += (l >> i) << i;
			if (cur >= l && cur <= r) {
				int cnt = 0;
				for (int j = 0; j < 64; j++) {
					if (cur & (1ll << j))
						cnt++;
				}
				if (cnt > bits) {
					bits = cnt;
					ans = cur;
				}
			} else {
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
