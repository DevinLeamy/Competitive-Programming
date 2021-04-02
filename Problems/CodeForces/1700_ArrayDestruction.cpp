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
using namespace std;
char _;

int cnt[1000001];
vector<PI> solve() {
	int n; cin >> n;
	vector<int> all(2*n);

	for (int i = 0; i < 2*n; i++) {
		cin >> all[i];
	}
	sort(all.begin(), all.end());

	for (int i = 0; i < 2*n - 1; i++) {
		vector<PI> ans;

		for (int val : all)
			cnt[val]++;
		int j = 2 * n - 1;
		int sum = all[j] + all[i];
		bool works = true;
		for (int h = 0; h < n; h++) {
			while (j > 0 && cnt[all[j]] == 0) {
				j--;
			}
			cnt[all[j]]--;
			cnt[sum - all[j]]--;
			ans.pb(make_pair(all[j], sum - all[j]));
			if (cnt[sum - all[j]] < 0 || cnt[all[j]] < 0) {
				works = false;
				cnt[all[j]] = 0;
				cnt[sum - all[j]] = 0;
				break;
			}
			sum = max(all[j], sum - all[j]);
		}
		for (int val : all)
			cnt[val] = 0;
		if (works) {
			return ans;
		}
	}
	return {};
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		vector<PI> res = solve();
		if (!res.empty()) {
			cout << "YES\n";
			cout << res[0].first + res[0].second << "\n";
			for (PI val : res) {
				cout << val.first << " " << val.second << "\n";
			}
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
