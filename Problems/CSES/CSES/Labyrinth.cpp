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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, m; cin >> n >> m;
	vector<vector<bool>> vis(n, vector<bool>(m));
	vector<vector<char>> last(n, vector<char>(m, '-'));
	PI start, end;
	
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			vis[i][j] = s[j] == '#';
			if (s[j] == 'A') {
				start.first = i;
				start.second = j;
			}
			if (s[j] == 'B') {
				end.first = i;
				end.second = j;
			}
		}
	}
	queue<pair<PI, char>> q;
	q.push(make_pair(start, ' '));
	while (!q.empty()) {
		pair<PI, char> cur = q.front(); q.pop();
		int row = cur.first.first;
		int col = cur.first.second;
		if (row < 0 || col < 0 || row >= n || col >= m)
			continue;
		if (last[row][col] != '-')
			continue;
		last[row][col] = cur.second;
		vis[row][col] = true;
		if (row == end.first && col == end.second) {
			break;
		}
		if (row != n - 1 && !vis[row + 1][col]) {
			q.push(make_pair(make_pair(row + 1, col), 'D'));
			vis[row + 1][col] = true;
		}
		if (row != 0 && !vis[row - 1][col]) {
			q.push(make_pair(make_pair(row - 1, col), 'U'));
			vis[row - 1][col] = true;
		}
		if (col != m - 1 && !vis[row][col + 1]) {
			q.push(make_pair(make_pair(row, col + 1), 'R'));
			vis[row][col + 1] = true;
		}
		if (col != 0 && !vis[row][col - 1]) {
			q.push(make_pair(make_pair(row, col - 1), 'L'));
			vis[row][col - 1] = true;
		}
	}
	if (!vis[end.first][end.second]) {
		cout << "NO\n";
		return 0;
	}
		
	string path = "";
	for (PI cur = end; cur != start; ) {
		path += string(1, last[cur.first][cur.second]);
		if (last[cur.first][cur.second] == 'D') {
			cur.first--;
		} else if (last[cur.first][cur.second] == 'U') {
			cur.first++;
		} else if (last[cur.first][cur.second] == 'L') {
			cur.second++;
		} else {
			cur.second--;
		}
	}
	reverse(path.begin(), path.end());
	printf("YES\n");
	printf("%d\n", (int) path.length());
	printf("%s\n", path.c_str());
	return 0;
}
