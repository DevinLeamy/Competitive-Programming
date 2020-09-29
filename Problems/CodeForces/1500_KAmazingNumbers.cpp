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
		vector<int> vals(n);
		vector<pair<vector<int>, int>> count(n+1);
		vector<int> minGap(n+1, -1);
//		vector<pair<vector<int>, int>> count(7);
//		vector<int> minGap(7, -1);
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
			if (count[vals[i]].first.size() == 0) {
				count[vals[i]].second = i+1;
			} else {
				int last = count[vals[i]].first.back();
				int gap = count[vals[i]].second;
				count[vals[i]].second = max(gap, i - last);
			}
			count[vals[i]].first.pb(i);
		}
		for (int i = 0; i < count.size(); i++) {
			if (count[i].first.size() == 0) continue;
			int last = count[i].first.back();
			int gap = count[i].second;
			int smallestGap = max(gap, n - last);
			if (minGap[smallestGap] == -1) {
				minGap[smallestGap] = i;
			}
		}
		int currentMin = INF;
		for (int i = 1; i <= n; i++) {
			if (minGap[i] == -1) {
				if (currentMin != INF) {
					cout << currentMin << " ";
				} else {
					cout << "-1 ";
				}
			} else {
				cout << min(currentMin, minGap[i]) << " ";
				currentMin = min(currentMin, minGap[i]);
			}
		}
		cout << endl;
	}
	return 0;
}
/*
1
6
1 3 1 5 3 1
 */
