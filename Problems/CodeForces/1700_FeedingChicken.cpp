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
		int n, m, k; cin >> n >> m >> k;
		vector<vector<bool>> rice(n, vector<bool>(m));
		vector<vector<char>> ans(n, vector<char>(m));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < m; j++) {
				rice[i][j] = (s[j] == 'R');
				if (rice[i][j]) cnt++;
			}
		}
		int more = cnt % k;
		int each = cnt / k;
		int cur = 0;
		int cur_r = 0;
		string ids = "1234567890AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
		int row = 0;
		int col = 0;
		bool rgt = true;
		int row_l = -1;
		int col_l = -1;
		while (row != n) {
			int add = (rice[row][col])? 1 : 0;
			cur_r += add;
			if (cur_r == 0 && row_l != -1) {
				ans[row][col] = ans[row_l][col_l];
			} else if (cur_r == each + 1) {
				ans[row][col] = ids[cur];
				more--;
				cur++;
				cur_r = 0;
			} else if (cur_r == each && more == 0) {
				ans[row][col] = ids[cur];
				cur++;
				cur_r = 0;
			} else {
				ans[row][col] = ids[cur];
			}
			row_l = row;
			col_l = col;
			if (rgt) col++;
			else col--;
			if (col == m) {
				row++;
				col = m-1;
				rgt = false;
			} else if (col == -1) {
				row++;
				col = 0;
				rgt = true;
			}
		}
		for (int i = 0; i < n; i++) {
			string line = "";
			for (char c : ans[i]) line += c;
			cout << line << "\n";
		}
	}
	return 0;
}
