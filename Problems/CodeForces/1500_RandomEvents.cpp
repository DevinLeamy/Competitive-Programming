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
		int n, m; cin >> n >> m;
		vector<int> vals(n);
		int last_unsorted = n;
		for (int i = 0; i < n; i++) cin >> vals[i];
		while (last_unsorted > 0 && vals[last_unsorted - 1] == last_unsorted) {
			last_unsorted--;
		}
		double ans = 0.0;
		double undecided = 1.0;
		for (int i = 0; i < m; i++) {
			int r; double p; cin >> r >> p;
			if (r >= last_unsorted) {
				double temp = undecided * p;
				ans += temp;
				undecided -= temp;
			}
		}
		if (last_unsorted == 0) {
			cout << 1 << endl;
			continue;
		}
		cout << ans << endl;
	}
	return 0;
}
