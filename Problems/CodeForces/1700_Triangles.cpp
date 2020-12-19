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
		int n; cin >> n;
		vector<vector<int>> grid;
		vector<vector<PI>> pts(10);
		string line;
		vector<int> maxr(10, -1), minr(10, INF),
					maxc(10, -1), minc(10, INF),
					ans(10);
		for (int i = 0; i < n; i++) {
			cin >> line;
			grid.pb(vector<int>(n));
			for (int j = 0; j < n; j++) {
				int val = line[j] - '0';
				grid[i][j] = val;
				pts[val].pb({i, j});
				maxr[val] = max(maxr[val], i); maxc[val] = max(maxc[val], j);
				minr[val] = min(minr[val], i); minc[val] = min(minc[val], j);
			}
		}
		for (int i = 0; i < 10; i++) {
			if (pts[i].size() < 2) continue;
			for (PI p1 : pts[i]) {
				{
					PI p2 = {
						p1.first,
						(p1.second > (n-1) - p1.second)? 0 : n-1
					};
					int base = abs(p1.second - p2.second);
					int h1 = abs(maxr[i] - p1.first);
					int h2 = abs(minr[i] - p1.first);
					ans[i] = max(ans[i], base * max(h1, h2));
				}
				{
					PI p2 = {
						(p1.first > (n-1) - p1.first)? 0 : n-1,
						p1.second
					};
					int base = abs(p1.first - p2.first);
					int h1 = abs(maxc[i] - p1.second);
					int h2 = abs(minc[i] - p1.second);
					ans[i] = max(ans[i], base * max(h1, h2));
				}
			}
		}
		for (int val : ans) cout << val << " ";
		cout << endl;
	}
	return 0;
}
