#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#define INF 2147483647
#define LINF 9223372036854775807ll
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define PL pair<long, long>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

int works = -1;
ll n, s, l, r;
bool valid(vector<PL>& vals, ll med) {
	vector<ll> cost;
	for (int i = 0; i < n; i++) {
		if (vals[i].first >= med) {
			cost.push_back(0);
		} else if (vals[i].second >= med) {
			cost.push_back(med - vals[i].first);
		}
	}
	if (cost.size() < n/2 + 1) {
		return false;
	}
	sort(cost.begin(), cost.end());
	
	ll sum = 0;
	for (int i = 0; i < (n/2) + 1; i++) {
		sum += cost[i];
	}
	if (sum > s) {
		return false;
	}
	return true;
}


ll binarySearch(ll low, ll high, vector<PL>& vals) {
	ll mid = (low + high) / 2;
	if (mid == low) {
		return low;
	} else if (low > high) {
		return low;
	}
	if (valid(vals, mid)) {
		return binarySearch(mid, high, vals);
	} else {
		return binarySearch(low, mid-1, vals);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	loop(t) {
		works = -1;
		ll low = LINF, high = -LINF, sum = 0;
		cin >> n >> s;
		vector<PL> vals;
		for (int i = 0; i < n; i++) {
			cin >> l >> r;
			vals.push_back({l, r});
			low = min(low, l);
			high = max(high, r);
			sum += l;
		}
		s -= sum;
		ll val = binarySearch(low, high, vals);
		if (valid(vals, val+1)) {
			cout << val + 1 << "\n";
		} else {
			cout << val << "\n";
		}
	}
	return 0;
}
