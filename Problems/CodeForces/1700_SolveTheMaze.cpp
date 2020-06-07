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
		int n, m; cin >> n >> m;
		vector<PI> good;
		vector<PI> bad;
		string line;
		vector<vector<bool>> wall;
		for (int i = 0; i < n; i++) {
			cin >> line; wall.pb(vector<bool>());
			for (int j = 0; j < m; j++) {
				if (line[j] == '#') {
					wall[i].pb(true);
				} else {
					wall[i].pb(false);
				}
				
				if (line[j] == 'G') {
					good.pb({i, j});
				} else if (line[j] == 'B') {
					bad.pb({i, j});
				}
			}
		}
		bool canEscape = true;
		//Block bad guys
		for (int i = 0; i < bad.size(); i++) {
			PI loc = bad[i];
			int row = loc.first;
			int col = loc.second;
			if (row == n-1 && col == m-1) {
				canEscape = false;
			}
			if (row != 0) {
				wall[row-1][col] = true;
			}
			if (row != n-1) {
				wall[row+1][col] = true;
			}
			if (col != 0) {
				wall[row][col-1] = true;
			}
			if (col != m-1) {
				wall[row][col+1] = true;
			}
		}
		if (!canEscape) {
			cout << "No" << endl;
			continue;
		} else if (good.size() == 0) {
			cout << "Yes" << endl;
			continue;
		}
		if (wall[n-1][m-1]) {
			cout << "No" << endl;
			continue;
		}
		vector<vector<bool>> visited;
		for (int i = 0; i < n; i++) {
			visited.pb(vector<bool>());
			for (int j = 0; j < m; j++) {
				visited[i].pb(wall[i][j]);
			}
		}
		queue<PI> q;
		q.push({n-1, m-1});
		while (!q.empty()) {
			PI cor = q.front(); q.pop();
			int row = cor.first;
			int col = cor.second;
			if (row != 0 && !visited[row-1][col]) {
				visited[row-1][col] = true;
				q.push({row-1, col});
			}
			if (row != n-1 && !visited[row+1][col]) {
				visited[row+1][col] = true;
				q.push({row+1, col});
			}
			if (col != 0 && !visited[row][col-1]) {
				visited[row][col-1] = true;
				q.push({row, col-1});
			}
			if (col != m-1 && !visited[row][col+1]) {
				visited[row][col+1] = true;
				q.push({row, col+1});
			}
		}
		for (int i = 0; i < good.size(); i++) {
			PI loc = good[i];
			if (wall[loc.first][loc.second] || !visited[loc.first][loc.second]) {
				canEscape = false;
			}
		}
		if (canEscape) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
		
	}
	return 0;
}
