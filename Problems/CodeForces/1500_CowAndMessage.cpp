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
	string s; cin >> s;
	
	
	int n = (int) s.length();
	ll ans = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			int cnt = 0;
			ll total = 0;
			for (int k = 0; k < n; k++) {
				if (s[k] - 'a' == j) total += cnt;
				if (s[k] - 'a' == i) cnt++;
			}
			ans = max(ans, total);
			ans = max(ans, (ll) cnt);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
