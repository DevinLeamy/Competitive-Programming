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
		int x; cin >> x;
		string ans((int)s.length(), '1');
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '1') continue;
			if (i - x >= 0) {
				ans[i-x] = '0';
			}
			if (i + x < s.length()) {
				ans[i + x] = '0';
			}
		}
		bool works = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0') continue;
			bool has = false;
			if (i - x >= 0 && ans[i-x] == '1') {
				has = true;
			}
			if (i + x < s.length() && ans[i+x] == '1') {
				has = true;
			}
			if (!has) works = false;
		}
		if (works) {
			cout << ans << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
