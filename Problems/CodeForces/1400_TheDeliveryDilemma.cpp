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

ll f(ll choice, vector<PL> &dil) {
	ll cost = 0;
	for (PL opt : dil) {
		if (opt.first > dil[choice].first)
			cost += opt.second;
	}
	return max(dil[choice].first, cost);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		vector<pair<ll, ll>> dil(n);
		for (int i = 0; i < n; i++) cin >> dil[i].first;
		for (int i = 0; i < n; i++) cin >> dil[i].second;
		dil.pb({0, 0});
		sort(dil.begin(), dil.end());
		int left = 0;
		int right = n;
		ll best = dil[n].first;
		while (left < right - 1) {
			int mid = (left + right)/2;
			ll fx = f(mid, dil);
			best = min(best, fx);
			if (fx > dil[mid].first) {
				left = mid;
			} else {
				right = mid;
			}
		}
		cout << min(best, min(f(left, dil), f(right, dil))) << endl;
	}
	return 0;
}
