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
		string s; cin >> s;
		vector<pair<int, int>> vals;
		vector<int> count;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0') {
				if (vals.size() == 0 || vals[vals.size()-1].first == 1) {
					vals.pb({0, 1});
				} else {
					vals[vals.size()-1].second++;
				}
			} else {
				if (vals.size() == 0 || vals[vals.size()-1].first == 0) {
					vals.pb({1, 1});
				} else {
					vals[vals.size()-1].second++;
				}
			}
		}
		for (int i = 0; i < vals.size(); i++) {
			if (vals[i].first == 1) {
				count.pb(vals[i].second);
			}
		}
		sort(count.begin(), count.end());
		int even = 0;
		int odd = 0;
		for (int i = 0; i < count.size(); i++) {
			if (i % 2 == 0) {
				even += count[i];
			} else {
				odd += count[i];
			}
		}
		cout << max(even, odd) << endl;
	}
	return 0;
}
