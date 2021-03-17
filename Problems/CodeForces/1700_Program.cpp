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
		int n, m; cin >> n >> m;
		string s; cin >> s;
		vector<int> vals;
		for (int i = 0; i < n; i++)
			vals.pb((s[i] == '+')? 1 : -1);
		
		vector<int> presum(1);
		
		for (int i = 0; i < n; i++)
			presum.pb(presum[i] + vals[i]);
		
		vector<PI> range_left(1, {0, 0});
		vector<PI> range_right(1, {0, 0});
		
		int cur = 0;
		for (int i = 0; i < n; i++) {
			PI prev = range_left[i];
			cur += vals[i];
			range_left.pb(make_pair(max(cur, prev.first), min(cur, prev.second)));
		}

		for (int i = 0; i < n; i++) {
			PI prev = range_right[i];
			int high = max(0, prev.first + vals[n - i - 1]); // Previous max "shifted" up or down
			int low = min(0, prev.second + vals[n - i - 1]); // Previous max "shifted" up or down
			range_right.pb(make_pair(high, low));
		}

		reverse(range_right.begin(), range_right.end());

		
		for (int i = 0; i < m; i++) {
			int l, r; cin >> l >> r;
			l--; r--;

			PI left = range_left[l];
			PI right = range_right[r + 1];
			int high = left.first;
			int low = left.second;

			int x = presum[l];


			high = max(right.first + x, high);
			low = min(right.second + x, low);
			cout << high - low + 1 << endl;
		}
	}
	
	return 0;
}
