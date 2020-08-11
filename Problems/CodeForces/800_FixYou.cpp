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

int n, m;
int sets = 1;
vector<vector<char>> adj;
vector<vector<int>> gro;

int dfs(int row, int col) {
	if (row < 0 || col < 0 || row >= n || col >= m) {
		sets++;
		return sets;
	} else if (gro[row][col] != -1) {
		return gro[row][col];
	} else {
		char loc = adj[row][col];
		if (loc == 'D') {
			int res = dfs(row + 1, col);
			gro[row][col] = res;
		} else {
			int res = dfs(row, col + 1);
			gro[row][col] = res;
		}
		return gro[row][col];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		cin >> n >> m;
		adj.clear();
		gro.clear();
		sets = 1;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			adj.pb(vector<char>());
			gro.pb(vector<int>());
			for (int j = 0; j < m; j++) {
				adj[i].pb(s[j]);
				gro[i].pb(-1);
			}
		}
		gro[n-1][m-1] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (gro[i][j] != -1) continue;
				dfs(i, j);
			}
		}
		cout << sets - 1 << endl;
	}
	return 0;
}
