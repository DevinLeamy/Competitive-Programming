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
		vector<pair<PL, int>> vals;
		vector<PL> raw(n);
		for (int i = 0; i < n; i++) {
			ll h, w; cin >> h >> w;
			
			if (h <= w)
				swap(h, w);
			
			raw[i].first = h;
			raw[i].second = w;
			vals.pb({{h, w}, i});
		}
		
		sort(vals.begin(), vals.end());
		
		vector<pair<PL, int>> best;
		ll smallest = vals[0].first.second;
		int idx = vals[0].second;
		for (int i = 0; i < n; i++) {
			pair<PL, int> val = vals[i];
			if (smallest > val.first.second) {
				smallest = val.first.second;
				idx = val.second;
			}
			val.first.second = smallest;
			val.second = idx;
			if (best.size() > 0) {
				if (best.back().first.first == val.first.first) {
					best[best.size() - 1] = val;
				} else {
					best.pb(val);
				}
			} else {
				best.pb(val);
			}
		}
		
		vector<int> ans(n, -1);
		for (int i = 0; i < n; i++) {
			int index = (int) (upper_bound(best.begin(), best.end(), make_pair(raw[i], i)) - best.begin()) - 2;
			if (index >= 0 && best[index].first.first < raw[i].first && best[index].first.second < raw[i].second) {
				ans[i] = best[index].second + 1;
			}
		}
		
		for (int val : ans)
			printf("%d ", val);
		printf("\n");
	}
	return 0;
}
