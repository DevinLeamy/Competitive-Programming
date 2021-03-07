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
		set<int> next_non;
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
			if (vals[i] > 1) {
				next_non.insert(i);
			}
		}
		
		ll res = 0;
		
		for (int i = 0; i < n - 1; i++) {
			if (vals[i] == 1) continue;
			if (vals[i] + i >= n) {
				ll change = (vals[i] - n) + 1 + i;
				res += change;
				vals[i] -= change;
			}
			while (vals[i] > 1) {
				for (int j = i; j < n; ) {
					ll bounce = vals[j];
					if (bounce == 1) {
						if (next_non.upper_bound(j) != next_non.end()) {
							j = *next_non.upper_bound(j);
						} else {
							j = n + 1;
						}
						continue;
					} else if (bounce == 2 && !next_non.empty()) {
						next_non.erase(next_non.find(j));
					}
					vals[j] = max(1ll, vals[j] - 1);
					j += bounce;
				}
				res += 1;
			}
		}
		if (vals[n-1] > 1) {
			res += vals[n-1] - 1;
		}

		cout << res << endl;
	}
	return 0;
}
