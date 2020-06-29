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
		ll a, sum = 0, max1 = -INF, end1 = 0, max2 = -INF, end2 = 0;
		vector<ll> vals;
		for (int i = 0; i < n; i++) {
			cin >> a; vals.pb(a);
			if (i%2 == 0) { sum += a; }
		}
		for (int i = 1; i < n; i+=2) {
			end1 += vals[i] - vals[i-1];
			if (max1 < end1) { max1 = end1; }
			if (end1 < 0) { end1 = 0; }
			if (i != n-1) {
				end2 += vals[i] - vals[i+1];
				if (max2 < end2) { max2 = end2; }
				if (end2 < 0) { end2 = 0; }
			}
		}
		cout << max(sum, max(max1, max2) + sum) << endl;
	}
	return 0;
}
