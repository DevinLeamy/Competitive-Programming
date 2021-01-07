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

ll f(ll cnt, vector<ll> &vals, vector<int> &fri) {
	ll sum = 0;
	ll cur = 0;
	for (int i = 0; i < (int) fri.size(); i++) {
		int idx = fri[i];
		if (idx < cnt) {
			sum += vals[idx];
		} else {
			sum += vals[cur];
			cur++;
		}
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	ll t; cin >> t;
	loop(t) {
		int n, m; cin >> n >> m;
		vector<int> fri(m+1);
		vector<ll> vals(m);
		
		ll total = 0;
		
		for (int i = 0; i < n; i++) {
			int a; cin >> a; a--;
			fri[a]++;
		}
		
		for (int i = 0; i < m; i++) cin >> vals[i];
		
		for (int i = 0; i <= m; i++) {
			total += fri[i] * vals[i];
		}
		
		ll min = total, cur = total, nxt = m;
		for (int i = 1; i <= std::min(n, m); i++) {
			while (fri[nxt] == 0) nxt--;
			cur -= vals[nxt];
			cur += vals[i-1];
			min = std::min(min, cur);
			fri[nxt]--;
		}
		
		printf("%lld\n", min);
	}
	return 0;
}
