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
	vector<PI> moves = {{1, 0}, {0, 1}};
	loop(t) {
		int n, m, a, sum = 0; cin >> n >> m;
		vector<vector<bool>> on(n);
		vector<vector<bool>> vis(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a; on[i].pb(a == 1);
				vis[i].pb(false);
			}
		}
		vector<PI> count(n+m - 1);
		queue<pair<PI, int>> cur;
		cur.push({{0, 0}, 0});
		while (!cur.empty()) {
			pair<PI, int> val = cur.front(); cur.pop();
			int row = val.first.first;
			int col = val.first.second;
			if (vis[row][col]) { continue; }
			int dist = val.second;
			if (on[row][col]) {
				count[dist].first++;
			}
			vis[row][col] = true;
			count[dist].second++;
			if (row == n-1 && col == m-1) { continue; }
			for (PI move : moves) {
				if (row + move.first != n && col + move.second != m) {
					if (!vis[row+move.first][col + move.second]) {
						cur.push({{row+move.first, col + move.second}, dist + 1});
					}
				}
			}
		}
		for (int i = 0; i < (n + m - 1)/2; i++) {
			int nei = (n + m - 2) - i;
			int totalCount = count[i].second + count[nei].second;
			int like = count[i].first + count[nei].first;
			sum += min(totalCount - like, like);
		}
		cout << sum << endl;
		
	}
	return 0;
}
