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
		int n; ll c; cin >> n >> c;
		vector<PL> vals(n);
		for (int i = 0; i < n; i++) {
			cin >> vals[i].first;
			vals[i].second = i;
		}
		vector<int> ans(n);
		sort(vals.begin(), vals.end());
		ll last = 0;
		bool black = true;
		for (int i = 0; i < n; i++) {
			if (vals[i].first * 2 > c) {
				ans[vals[i].second] = 1;
			} else if (vals[i].first * 2 < c) {
				ans[vals[i].second] = 0;
			} else {
				if (last == vals[i].first) {
					if (black) {
						ans[vals[i].second] = 0;
					} else {
						ans[vals[i].second] = 1;
					}
					black = !black;
				} else {
					ans[vals[i].second] = 0;
					black = !black;
				}
			}
			last = vals[i].first;
		}
//
//		int lp = 0;
//		int rp = n-1;
//		while (lp < rp) {
//			if (vals[lp].first + vals[rp].first != c) {
//				ans[vals[lp].second] = 1;
//				ans[vals[rp].second] = 1;
//				lp++;
//				rp--;
//			} else {
//				ans[vals[lp].second] = 0;
//				ans[vals[rp].second] = 1;
//				lp++;
//				rp--;
//			}
//		}
//		if (lp == rp) {
//			ans[vals[lp].second] = 0;
//		}
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		
	}
	return 0;
}
