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
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;
char _;

vector<pair<string, PI>> ans;
 
void print_red(int i, int j) {
	ans.pb({"R", {i + 1, j + 1}});
}
 
void print_blue(int i, int j) {
	ans.pb({"B", {i + 1, j + 1}});
}
 
void destroy(int i, int j) {
	ans.pb({"D", {i + 1, j + 1}});
}

int n, m;

void fill_space(int row, int col, vector<vector<bool> > &state, int depth, vector<vector<bool> > &visited) {
	int left = col;
	int right = col;
	
	for (int i = col - 1; i >= 0; i--) {
		if (!state[row][i])
			break;
		left = i;
	}
	for (int i = col + 1; i < m; i++) {
		if (!state[row][i])
			break;
		right = i;
	}
	
	for (int i = left; i <= right; i++)
		visited[row][i] = true;
	for (int i = left; i <= right; i++) {
		if (row != n - 1 && state[row + 1][i]) {
			if (!visited[row + 1][i])
				fill_space(row + 1, i, state, depth + 1, visited);
		}
		if (row != 0 && state[row - 1][i]) {
			if (!visited[row - 1][i])
				fill_space(row - 1, i, state, depth + 1, visited);
		}
	}
	for (int i = left; i < col; i++) {
		if (i == col)
			continue;
		destroy(row, i);
		print_red(row, i);
		state[row][i] = false;
	}
	for (int i = right; i > col; i--) {
		if (i == col)
			continue;
		destroy(row, i);
		print_red(row, i);
		state[row][i] = false;
	}
	if (depth == 0) {
		state[row][col] = false;
		return;
	}
	destroy(row, col);
	print_red(row, col);
	state[row][col] = false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	cin >> n >> m;
	
	// 0: empty, 1: red, 2: blue, -1: blocked (or visited)
	vector<vector<bool> > state(n, vector<bool>(m));
	vector<vector<bool> > visited(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++)
			state[i][j] = (s[j] == '.')? true : false;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (state[i][j]) {
				print_blue(i, j);
			}
		}
	}
	vector<int> prev = {-1, -1, -1};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (state[i][j])
				fill_space(i, j, state, 0, visited);
		}
	}
	cout << ans.size() << endl;

	for (auto val : ans)
		printf("%s %d %d\n", val.first.c_str(), val.second.first, val.second.second);
	
	return 0;
}
