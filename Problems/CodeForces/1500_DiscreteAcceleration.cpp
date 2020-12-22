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
		int n; ll l; cin >> n >> l;
		vector<ll> vals(n+2);
		for (int i = 0; i < n; i++) cin >> vals[i+1];
		vals[n+1] = l;
		ll lp = 0, rp = l;
		vector<double> t1(n+2), t2(n+2);
		for (int i = 1; i <= n+1; i++) {
			ll nxt = vals[i];
			ll dst = nxt - lp;
			double time = (double) dst / (double) (i);
			t1[i] = time + t1[i-1];
			lp = vals[i];
		}
		for (int i = n; i >= 0; i--) {
			ll nxt = vals[i];
			ll dst = rp - nxt;
			double time = (double) dst / (double) (n - i + 1);
			t2[i] = time + t2[i+1];
			rp = vals[i];
		}
		
		double ans = -1;
		for (int i = 0; i < n + 2; i++) {
			double val1 = t1[i];
			double val2 = t2[i];
			if (val2 <= val1) {
				double s1 = i;
				double s2 = n - i + 2;
			
				double cur_time = t1[i-1];
				double dst = vals[i] - s2 * (cur_time - val2);
				if (i != 0) { dst -= vals[i-1]; }
				
				double delta = dst / (s1 + s2);
				ans = cur_time + delta;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
