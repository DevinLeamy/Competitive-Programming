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
	ll a, ans = 0; vector<ll> vals;
	vector<int> count(21);
	for (int i = 0; i < n; i++) { cin >> a; vals.pb(a);
		int cur = 0;
		while (a) {
			if (a & 1) {
				count[cur]++;
			}
			a >>= 1;
			cur++;
		}
	}
	for (int j = 0; j < n; j++) {
		ll val = 0;
		for (int i = 0; i <= 20; i++) {
			if (count[i] > 0) {
				count[i]--;
				val += pow(2, i);
			}
		}
		ans += (val * val);
	}
	cout << ans << endl;
	return 0;
}
