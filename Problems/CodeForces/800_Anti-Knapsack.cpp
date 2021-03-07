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
		int k, n; cin >> n >> k;
		int cnt = 0;
		vector<int> ans;
		for (int i = k+1; i <= n; i++) {
			cnt++;
			ans.pb(i);
		}
		for (int i = 1; i <= k-1; i++) {
			if (k - i > i) continue;
			cnt++;
			ans.pb(i);
		}
		cout << (int) ans.size() << endl;
		for (int val : ans) {
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
