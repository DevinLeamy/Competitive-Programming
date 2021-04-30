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

int MAXN = 300005;
vector<ll> vals(MAXN);
vector<pair<bool, bool>> hv(MAXN);
int solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	int cur = 0;
	for (int i = 1; i < n - 1; i++) {
		if (vals[i] > vals[i - 1] && vals[i] > vals[i + 1]) {
			hv[i].first = true;
			hv[i].second = false;
			cur++;
		} else if (vals[i] < vals[i - 1] && vals[i] < vals[i + 1]) {
			hv[i].first = false;
			hv[i].second = true;
			cur++;
		} else {
			hv[i].first = false;
			hv[i].second = false;
		}
	}
	int ans = cur;
	for (int i = 0; i < n; i++) {
		ll temp = vals[i];
		int cnt = 0;
		for (int j = max(1, i - 3); j <= min(n - 2, i + 3); j++) {
			if (hv[j].first || hv[j].second) {
				cnt++;
			}
		}
		if (i != 0) {
			vals[i] = vals[i - 1];
			int cnt2 = 0;
			for (int j = max(1, i - 3); j <= min(n - 2, i + 3); j++) {
				if (vals[j] > vals[j - 1] && vals[j] > vals[j + 1]) {
					cnt2++;
				} else if (vals[j] < vals[j - 1] && vals[j] < vals[j + 1]) {
					cnt2++;
				}
			}
			ans = min(ans, cur - (cnt - cnt2));
		}
		if (i != n) {
			vals[i] = vals[i + 1];
			int cnt2 = 0;
			for (int j = max(1, i - 3); j <= min(n - 2, i + 3); j++) {
				if (vals[j] > vals[j - 1] && vals[j] > vals[j + 1]) {
					cnt2++;
				} else if (vals[j] < vals[j - 1] && vals[j] < vals[j + 1]) {
					cnt2++;
				}
			}
			ans = min(ans, cur - (cnt - cnt2));
		}
		vals[i] = temp;
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
