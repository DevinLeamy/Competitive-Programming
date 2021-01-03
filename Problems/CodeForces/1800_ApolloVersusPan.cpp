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

ll mod = 1000000007ll;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		vector<ll> vals(n);
		for (int i = 0; i < n; i++) cin >> vals[i];
		
		vector<int> bit_cnt(60);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 60; j++) {
				if ((1LL << j) & vals[i])
					bit_cnt[j]++;
			}
		}
		ll ans = 0;
			
		for (ll val : vals) {
			ll a = 0, b = 0;
			for (int i = 0; i < 60; i++) {
				ll p = (1LL << i);
				if (val & p) {
					a = ((p % mod) * n + a) % mod;
					b = ((p % mod) * bit_cnt[i] + b) % mod;
				} else {
					a = ((p % mod) * bit_cnt[i] + a) % mod;
				}
			}
			ans = (ans + a * b) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
