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
		int ans = 0, lp = 0, rp = k-1;
		while (lp <= rp) {
			vector<int> cnt(26);
			int ttl = 0;
			for (int j = lp; j < n; j += k) {
				ttl++;
				cnt[s[j] - 'a']++;
				if (lp != rp) {
					ttl++;
					cnt[s[j + rp - lp] - 'a']++;
				}
			}
			int min = ttl - cnt[0];
			for (int val : cnt) min = std::min(min, ttl - val);
			ans += min;
			lp++;
			rp--;
		}
		printf("%i\n", ans);
	}
	return 0;
}
