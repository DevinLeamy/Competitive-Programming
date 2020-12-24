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

//bool works(vector<int> vals) {
//	int cur = vals[0];
//	for (int i = 1; i < vals.size(); i++) {
//		int temp = cur ^ vals[i];
//		if (temp <= cur) return false;
//		cur = temp;
//	}
//	return true;
//}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		ll d, m; cin >> d >> m;
		vector<ll> cnt;
		ll rem = d;
		for (int i = 0; i < 64; i++) {
			cnt.pb(min((ll) pow(2, i), rem));
			rem -= pow(2, i);
			if (rem <= 0) break;
		}
		int n = (int) cnt.size();
		vector<ll> ans(n);
		vector<ll> cur(cnt);
		ll sum = 0;
		for (ll val : cnt) sum = (sum + val) % m;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n-i; j++) {
				ll total = 0;
				for (int k = j+1; k < n - i + 1; k++) {
					sum = (sum + (cnt[j]*cur[k])) % m;
					total = (total + (cnt[j]*cur[k])) % m;
				}
				cur[j] = total % m;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
