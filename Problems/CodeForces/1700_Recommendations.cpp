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
	int n; cin >> n;
	vector<PL> pubs(n);
	multiset<ll, greater<ll>> set;
	for (int i = 0; i < n; i++) cin >> pubs[i].first;
	for (int i = 0; i < n; i++) cin >> pubs[i].second;
	sort(pubs.begin(), pubs.end());
	ll last = pubs[0].first;
	ll ans = 0;
	ll sum = pubs[0].second;
	set.insert(pubs[0].second);
	for (int i = 1; i < n; i++) {
		PL val = pubs[i];
		if (val.first != last) {
			ll dif = val.first - last;
			ll temp = dif;
			ll dist = 0;
			auto iter = set.begin();
			while (dif > 0 && set.size() > 0) {
				ll time = *iter;
				ans += dist * time;
				sum -= time;
				set.erase(iter);
				dist++;
				dif--;
				iter = set.begin();
			}
			ans += (ll)temp * sum;
		}
		sum += val.second;
		set.insert(val.second);
		last = val.first;
	}
	ll dist = 0;
	auto iter = set.begin();
	while (set.size() > 0) {
		ll time = *iter;
		ans += dist * time;
		sum -= time;
		set.erase(iter);
		dist++;
		iter = set.begin();
	}
	cout << ans << endl;
	return 0;
}
