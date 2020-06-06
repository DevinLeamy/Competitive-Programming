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
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		vector<vector<int>> x(n+1); x[n].pb(0);
		vector<int> ans(n);
		int count = 1;
		for (int i = n; i >= 1; i--) {
			sort(x[i].begin(), x[i].end());
			for (int j = 0; j < x[i].size(); j++) {
				int l = x[i][j];
				int r = x[i][j] + i - 1;
				int index;
				if (i % 2 == 1) { index = (l + r) / 2; }
				else { index = (l + r - 1) / 2; }
				ans[index] = count;
				int lS = index - l;
				if (lS > 0) { x[lS].pb(l); }
				int rS = r - index;
				if (rS > 0) { x[rS].pb(index+1); }
				count++;
			}
		}
		for (int num : ans) { cout << num << " "; }
		cout << "\n";
	}
	return 0;
}
