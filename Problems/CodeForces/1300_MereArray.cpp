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
		int n; cin >> n;
		vector<ll> vals(n);
		vector<ll> a1;
		vector<ll> a2;
		ll min = LINF;
		for (int i = 0; i < n; i++) {
			ll a; cin >> a;
			vals[i] = a;
			min = std::min(min, vals[i]);
		}
		vector<bool> div(n);
		for (int i = 0; i < n; i++) {
			if (vals[i] % min == 0) {
				a1.pb(vals[i]);
				div[i] = true;
			} else {
				a2.pb(vals[i]);
			}
		}
		sort(a1.begin(), a1.end());
		int p1 = 0, p2 = 0;
		bool works = true;
		ll last = -LINF;
		for (int i = 0; i < n; i++) {
			if (div[i]) {
				if (a1[p1] < last) works = false;
				last = a1[p1];
				p1++;
			} else {
				if (a2[p2] < last) works = false;
				last = a2[p2];
				p2++;
			}
		}
		cout << (works? "YES":"NO") << endl;
	}
	return 0;
}
