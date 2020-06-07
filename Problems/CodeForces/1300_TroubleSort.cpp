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
		int n, a; cin >> n;
		vector<pair<int, PI>> vals;
		vector<bool> type;
		PI f = { false, false };
		for (int i = 0; i < n; i++) {
			cin >> a;
			vals.pb({a, {i, false}});
		}
		for (int i = 0; i < n; i++) {
			cin >> a;
				vals[i].second.second = (a==1);
			type.pb(a==1);
			if (a == 1) {f.first = true; }
			if (a == 0) {f.second = true; }
		}
		if (f.first == true && f.second == true) {
			cout << "Yes" << endl;
		} else {
			bool sorted = true;
			for (int i = 1; i < n; i++) {
				if (vals[i].first < vals[i-1].first) {
					sorted = false;
				}
			}
			if (sorted) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
//		sort(vals.begin(), vals.end());
//		bool can = true;
//		for (int i = 0; i < n; i++) {
//			if (vals[i].second.first != i) {
//				if (type[i] == vals[i].second.second) {
//					can = false;
//				}
//			}
//		}
//		if (can) {
//			cout << "Yes" << endl;
//		} else {
//			cout << "No" << endl;
//		}
	}
	return 0;
}
