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
		vector<ll> vals(n);
		map<ll, ll> has;
		for (int i = 0; i < n; i++) {
			ll a; cin >> a;
			ll val = k - (a % k);
			if (val != k) {
				if (has[val]) {
					ll temp = val;
					val += k * has[val];
					has[temp]++;
				} else {
					has[val] = 1;
				}
			}
			vals[i] = val;
		}
		sort(vals.begin(), vals.end());
		ll ops = 0;
		ll x = 0;
		for (int i = 0; i < n; i++) {
			if (vals[i] != k) {
				if (vals[i] == x) {
					ops++;
					x++;
				} else {
					ops += (vals[i] - x) + 1;
					x += (vals[i] - x) + 1;
				}
			}
		}
		cout << ops << endl;
	}
	return 0;
}
