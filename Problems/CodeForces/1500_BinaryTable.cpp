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

vector<string> output;
void change(int row, int col, vector<PI> toChange, vector<vector<bool>> &block) {
	string line = "";
	for (PI cord : toChange) {
		int row1 = cord.first - row;
		int col1 = cord.second - col;
		block[row1][col1] = !block[row1][col1];
		line += to_string(cord.first) + " " + to_string(cord.second) + " ";
	}
	output.pb(line);
}

// you can assume that after fixset is called all blocks in the set will be zero
void fixset(int row, int col, vector<vector<bool>> &block) {
	vector<PI> zeros, ones;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (block[i][j]) zeros.pb({row + i, col + j});
			else ones.pb({row + i, col + j});
		}
	}
	if (zeros.size() == 4) return;
	else if (zeros.size() == 3) {
		PI zero2 = (zeros[0].first == zeros[1].first || zeros[0].second == zeros[1].second)? zeros[1] : zeros[2];
		change(row, col, {zeros[0], zero2, ones[0]}, block);
	} else if (zeros.size() == 2) {
		// check if they are adj or across
		int diff = abs(zeros[0].first - zeros[1].first)
				+  abs(zeros[0].second - zeros[1].second);
		
		if (diff == 1) change(row, col, {zeros[0], zeros[1], ones[0]}, block);
		else change(row, col, {zeros[0], ones[0], ones[1]}, block);
	} else {
		change(row, col, {ones[0], ones[1], ones[2]}, block);
	}
	fixset(row, col, block);
}



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n, m; cin >> n >> m;
		string line;
		vector<vector<bool>> tbl(n);
		output.erase(output.begin(), output.end());
		for (int i = 0; i < n; i++) {
			cin >> line;
			for (int j = 0; j < m; j++) {
				tbl[i].pb(line[j] == '0');
			}
		}
		for (int i = 0; i < n-1; i += 2) {
			for (int j = 0; j < m-1; j += 2) {
				vector<vector<bool>> block = {
					{tbl[i][j], tbl[i][j+1]},
					{tbl[i+1][j], tbl[i+1][j+1]},
				};
				fixset(i+1, j+1, block);
				tbl[i][j] = tbl[i][j+1] = true;
				tbl[i+1][j] = tbl[i+1][j+1] = true;
				if (m % 2 == 1 && j + 2 >= m-1) j--;
			}
			if (n % 2 == 1 && i + 2 >= n-1) i--;
		}
		cout << (int) output.size() << "\n";
		for (string line : output) {
			cout << line << "\n";
		}
	}
	return 0;
}
