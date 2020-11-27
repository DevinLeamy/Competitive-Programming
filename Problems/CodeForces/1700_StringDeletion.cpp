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
		string s; cin >> s;
		vector<int> cnt;
		char last = s[0];
		int cur = 0;
		for (int i = 1; i < n; i++) {
			if (s[i] == last) {
				cur++;
			} else {
				cnt.pb(cur);
				cur = 0;
				last = s[i];
			}
		}
		cnt.pb(cur);
		int ans = 0;
		int pnt = 0;
		for (int i = 0; i < cnt.size(); i++) {
			pnt = max(pnt, i);
			while (pnt < cnt.size() && cnt[pnt] == 0) {
				pnt++;
			}
			if (pnt == cnt.size()) {
				ans += ceil(((double)cnt.size() - i)/2.0);
				break;
			} else {
				ans++;
				cnt[pnt]--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
