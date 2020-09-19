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
		int n; ll k, y; cin >> n >> k;
		vector<ll> vals(n);
		for (int i = 0; i < n; i++) cin >> vals[i];
		for (int i = 0; i < n; i++) cin >> y;
		sort(vals.begin(), vals.end());
		vector<int> points(n);
		vector<int> suffMax(n);
		for (int i = 0; i < n; i++) {
			int end = (int) (upper_bound(vals.begin(), vals.end(), vals[i] + k) - vals.begin());
			points[i] = end - i;
		}
		suffMax[n-1] = points[n-1];
		for (int i = n-2; i >= 0; i--)
			suffMax[i] = max(points[i], suffMax[i+1]);
		
		int max = 0;
		for (int i = 0; i < n; i++) {
			int first = points[i];
			int second = 0;
			if (i + first < n)
				second = suffMax[i+first];
			max = std::max(max, first + second);
		}
		cout << max << endl;
	}
	return 0;
}
