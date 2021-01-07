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
	ll t; cin >> t;
	loop(t) {
		int n; ll x; cin >> n >> x;
		vector<ll> vals(n);
		ll sum = 0;
		vector<ll> cnt(n);
		ll min = INF;
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
			sum += vals[i];
			ll temp = vals[i];
			while (temp % x == 0) {
				temp /= x;
				cnt[i]++;
			}
			min = std::min(min, cnt[i]);
		}
		sum += sum * min;
		for (int i = 0; i < n; i++) {
			if (cnt[i] == min) break;
			sum += vals[i];
		}
		printf("%lld\n", sum);
	}
	return 0;
}
