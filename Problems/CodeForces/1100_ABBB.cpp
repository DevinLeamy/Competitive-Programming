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
		string s; cin >> s;
		int as = 0;
		int bs = 0;
		int ans = (int) s.length();
		vector<int> vals;
		for (int i = (int) s.length() - 1; i >= 0; i--) {
			if (s[i] == 'A') {
				if (bs > 0) {
					ans -= 2;
					bs--;
				}
			} else {
				bs++;
			}
		}
		ans -= (bs / 2) * 2;
		cout << ans << endl;
	}
	return 0;
}
