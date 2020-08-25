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
		ll count = 0;
		ll max = 0;
		vector<ll> vals(n);
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
			max = std::max(max, vals[i]);
		}
		ll last = vals[0];
		int index = 1;
		ll maxSoFar = vals[0];
		while (index != n && vals[index] >= last) {
			last = vals[index];
			maxSoFar = std::max(maxSoFar, last);
			index++;
		}
		
		while (index != n) {
			ll min = LINF;
			ll cMax = -LINF;
			while (index != n && vals[index] <= last) {
				min = vals[index];
				last = vals[index];
				maxSoFar = std::max(maxSoFar, last);
				index++;
			}
			while (index != n && vals[index] >= last) {
				cMax = vals[index];
				last = vals[index];
				index++;
			}
			if (cMax == -LINF) {
				break;
			}
			count += std::min(maxSoFar,cMax) - min;
			maxSoFar = std::max(maxSoFar, cMax);
		}
		if (last < max) {
			count += max - last;
		}
		cout << count << endl;
	}
	return 0;
}
/*
 
1
11
3 5 1 1 2 1 3 1 6 6 5
 */
