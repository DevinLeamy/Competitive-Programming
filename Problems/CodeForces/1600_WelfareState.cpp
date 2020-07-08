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
	vector<pair<int, ll>> vals(n);
	for (int i = 0; i < n; i++) { cin >> vals[i].second; vals[i].first = 0; }
	int q, t, p, a; cin >> q;
	vector<pair<int, ll>> payouts;
	vector<ll> suff(q + 1);
	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> p >> a;
			vals[p - 1].first = i;
			vals[p - 1].second = a;
		} else {
			cin >> a;
			payouts.pb({i, a});
		}
	}
	if (payouts.size() == 0) {
		for (int i = 0; i < n; i++) {
			cout << vals[i].second << " ";
		}
		return 0;
	}
	int cur = (int) payouts.size() - 1;
	int index = payouts[cur].first;
	while (index >= 0) {
		if (cur >= 0 && index == payouts[cur].first) {
			suff[index] = payouts[cur].second;
			cur--;
		}
		suff[index] = max(suff[index], suff[index + 1]);
		index--;
	}
	for (int i = 0; i < n; i++) {
		cout << max(vals[i].second, suff[vals[i].first]) << " ";
	}
	return 0;
}
