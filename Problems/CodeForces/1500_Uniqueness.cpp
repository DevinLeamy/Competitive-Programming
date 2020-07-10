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
	set<ll> vis;
	int ans = INF;
	for (int i = 0; i < n; i++) { cin >> vals[i]; }
	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < i; j++) {
			ll val = vals[j];
			if (vis.count(val)) {
				flag = true;
			}
			vis.insert(val);
		}
		
		int min = n;
		for (int j = n-1; j >= i; j--) {
			ll val = vals[j];
			if (!vis.count(val)) {
				min = j;
			} else {
				break;
			}
			vis.insert(val);
		}
		if (!flag) {
			ans = std::min(ans, min - i);
		}
		vis.clear();
	}
	cout << ans << endl;
	return 0;
}
