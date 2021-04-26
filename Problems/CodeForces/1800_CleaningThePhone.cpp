#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
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
#define view(h) cout<<"DEBUG: " << h << endl
#define view2(a, b) cout << "DEBUG: " << a << " " << b << endl;
using namespace std;
char _;

int solve() {
	int n; ll m; cin >> n >> m;
	vector<ll> vals(n);
	vector<ll> b1;
	vector<ll> b2;
	
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
		sum += vals[i];
	}
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		if (t == 1)
			b1.pb(vals[i]);
		else
			b2.pb(vals[i]);
	}
	
	if (sum < m)
		return -1;
	
	sort(b1.rbegin(), b1.rend());
	sort(b2.begin(), b2.end());
	
	vector<ll> presum((int) b1.size() + 1);
	presum[0] = 0;
	for (int i = 0; i < b1.size(); i++)
		presum[i + 1] = presum[i] + b1[i];
	
	ll cur = 0;
	int only_b1 = (int) (lower_bound(presum.begin(), presum.end(), m) - presum.begin());
	int ans = (only_b1 >= 0 && only_b1 < (int) presum.size() && presum[only_b1] >= m)? only_b1 : INF;
	int b2_val = 0;
	while (!b2.empty()) {
		b2_val += 2;
		cur += b2.back(); b2.pop_back();
		int idx = (int) (lower_bound(presum.begin(), presum.end(), m - cur) - presum.begin());
		if (idx >= 0 && idx < (int) presum.size() && cur + presum[idx] >= m)
			ans = min(ans, b2_val + idx);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		printf("%d\n", solve());
	}
	return 0;
}
