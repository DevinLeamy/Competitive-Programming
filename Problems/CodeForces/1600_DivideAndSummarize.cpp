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
		int n, q; cin >> n >> q;
		ll max = -1;
		vector<ll> temp(n);
		vector<ll> sums;
		for (int i = 0; i < n; i++) {
			cin >> temp[i];
			max = std::max(max, temp[i]);
		}
		vector<ll> vals(max + 1);
		for (ll val : temp) vals[val]++;
		vector<ll> pre(1);
		for (int i = 1; i < vals.size(); i++) {
			pre.pb(pre[i-1] + vals[i] * i);
		}
		queue<PL> queue;
		queue.push({0, max});
		sums.pb(pre[max]);
		while (queue.size()) {
			PL cur = queue.front();
			queue.pop();
			
			ll lp = cur.first;
			ll rp = cur.second;
			
			while (vals[rp] == 0) rp--;
			while (lp < rp && vals[lp] == 0) lp++;
			
			ll mid = (lp + rp)/2;
			sums.pb(pre[rp] - pre[mid]);
			sums.pb(pre[mid] - pre[lp - 1]);
			
			if (mid + 1 <= rp) queue.push({mid + 1, rp});
			if (mid != rp) queue.push({lp, mid});
		}
		sort(sums.begin(), sums.end());
		for (int i = 0; i < q; i++) {
			ll s; cin >> s;
			if (binary_search(sums.begin(), sums.end(), s)) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
	return 0;
}
