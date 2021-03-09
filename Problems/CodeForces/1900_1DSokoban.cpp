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

int solve(vector<ll> pos, vector<ll> special) {
	if (pos.size() == 0 || special.size() == 0) return 0;
	int n = (int) pos.size();
	int m = (int) special.size();
	vector<int> on_special(m + 1);
	for (int i = 0; i < n; i++) {
		if (binary_search(special.begin(), special.end(), pos[i]))
			on_special[lower_bound(special.begin(), special.end(), pos[i]) - special.begin()]++;
	}
	for (int i = m - 1; i >= 0; i--)
		on_special[i] += on_special[i + 1];
	for (int i = 0; i < n; i++)
		pos[i] -= i;
	
	int max = 0;
	int start = (int) (lower_bound(special.begin(), special.end(), pos[0]) - special.begin());
	for (int i = start; i < m; i++) {
		ll left = special[i];
		ll blocks = upper_bound(pos.begin(), pos.end(), left) - pos.begin();
		ll right = left + blocks - 1;
		
		ll end_index = upper_bound(special.begin(), special.end(), right) - special.begin();
		int cnt = on_special[end_index];
		
		ll between = (int) end_index - i;
		cnt += between;
		
		
		max = std::max(max, cnt);
	}
	return max;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n, m; cin >> n >> m;
		vector<ll> pos_i, neg_i, pos_s, neg_s;
		for (int i = 0; i < n; i++) {
			ll a; cin >> a;
			if (a < 0)
				neg_i.pb(a * -1);
			else
				pos_i.pb(a);
		}
		for (int j = 0; j < m; j++) {
			ll a; cin >> a;
			if (a < 0)
				neg_s.pb(a * -1);
			else
				pos_s.pb(a);
		}
		sort(pos_i.begin(), pos_i.end());
		sort(neg_i.begin(), neg_i.end());
		sort(pos_s.begin(), pos_s.end());
		sort(neg_s.begin(), neg_s.end());
		
		int ans = 0;
		ans += solve(pos_i, pos_s);
		ans += solve(neg_i, neg_s);
		cout << ans << endl;
	}
	return 0;
}
