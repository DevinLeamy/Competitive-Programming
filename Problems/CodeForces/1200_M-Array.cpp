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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n, m; cin >> n >> m;
		vector<int> vals(100001);
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			vals[a % m]++;
		}
		int cnt = 0;
		if (vals[0] > 0)
			cnt++;
		for (int i = 1; i < m; i++) {
			int val = i;
			if (vals[val] == 0)
				continue;
			int rem = m - val;
			int max = min(vals[val], vals[rem]);
			vals[val] -= max;
			vals[rem] -= max;
			if (vals[val] > 0)
				vals[val]--;
			else if (vals[rem] > 0)
				vals[rem]--;
			cnt++;
			cnt += std::max(0, vals[val]);
		}
		printf("%d\n", cnt);
	}
	return 0;
}
