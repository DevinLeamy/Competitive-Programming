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
		int n; ll k; cin >> n >> k;
		ll l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
		if (l2 < l1) {
			ll temp1 = l1;
			ll temp2 = r1;
			l1 = l2;
			r1 = r2;
			l2 = temp1;
			r2 = temp2;
		}
		ll costTillIntersect = 0;
		if (r1 < l2) {
			costTillIntersect = l2 - r1;
		}
		ll timeAddOnePlusOne = max(r2, r1) - min(l1, l2);
		if (r1 >= r2) {
			timeAddOnePlusOne -= r2 - l2;
			k -= (r2 - l2) * n;
		} else if (costTillIntersect == 0 && r1 <= r2) {
			timeAddOnePlusOne -= r1 - l2;
			k -= (r1 - l2) * n;
		}
		k = max(0ll, k);
		
		ll best = LINF;
		for (int i = 0; i < n; i++) {
			ll currentTime = costTillIntersect * (i+1);
			ll intsec = min(k, timeAddOnePlusOne * (i+1));
			currentTime += (k - intsec) * 2 + intsec;
			best = min(currentTime, best);
		}
		cout << best << endl;
	}
	return 0;
}
