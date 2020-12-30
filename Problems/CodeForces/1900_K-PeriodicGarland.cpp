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
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector<bool> on(n);
		int on_cnt = 0;
		for (int i = 0; i < n; i++) {
			on[i] = s[i] == '1';
			if (on[i]) on_cnt++;
		}
		int ans = on_cnt;
		for (int i = 0; i < k; i++) {
			int value = on_cnt;
			vector<bool> bin;
			for (int j = i; j < n; j += k) {
				if (on[j]) value--;
				bin.pb(on[j]);
			}
			int m = (int) bin.size();
			// [0] = all 0's until i, first 1 at i, continuing 1's before i, last 1 was before i
			vector<int> cur = { 0, 1, 1, 0 };
			if (bin[0]) cur = { 1, 0, 0, 1};
			for (int j = 1; j < m; j++) {
				vector<int> new_cur;
				if (bin[j]) {
					new_cur = { cur[0] + 1,
								cur[0],
								min(cur[2], min(cur[0], cur[1])),
								min(cur[1], min(cur[2], cur[3])) + 1
							};
				} else {
					new_cur = { cur[0],
								cur[0] + 1,
								min(cur[2], min(cur[0], cur[1])) + 1,
								min(cur[1], min(cur[2], cur[3]))
							};
				}
				swap(cur, new_cur);
			}
			// Minimum number of digits that must change
			int cost = min( min(cur[0], cur[1]), min(cur[2], cur[3]) );
			ans = min(ans, value + cost);
		}
		printf("%d\n", ans);
	}
	return 0;
}
