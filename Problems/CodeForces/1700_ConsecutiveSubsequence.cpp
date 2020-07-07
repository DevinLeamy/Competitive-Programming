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
	vector<ll> vals(n);
	vector<pair<int, int>> dp(n);
	map<ll, int > rec;
	for (int i = 0; i < n; i++) { cin >> vals[i]; dp[i] = { 1, -1 }; }
	pair<int, int> max = {1, 0};
	for (int i = 0; i < n; i++) {
		ll val = vals[i];
		if (rec.find(val - 1) != rec.end()) {
			int index = rec[val-1];
			dp[i].first = dp[index].first + 1;
			dp[i].second = index;
			if (max.first < dp[i].first) {
				max.first = dp[i].first;
				max.second = i;
			}
		}
		rec[val] = i;
	}
	vector<int> ans;
	int cur = max.second;
	ans.pb(max.second);
	while (cur != -1 && dp[cur].second != -1) {
		ans.pb(dp[cur].second);
		cur = dp[cur].second;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int val : ans) {
		cout << val + 1 << " ";
	}
	return 0;
}
