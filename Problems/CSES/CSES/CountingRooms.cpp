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
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++)
			vis[i][j] = s[j] == '#';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j])
				continue;
			cnt++;
			queue<PI> q;
			q.push(make_pair(i, j));
			while (!q.empty()) {
				PI cur = q.front(); q.pop();
				if (cur.first < 0 || cur.second < 0 || cur.first >= n || cur.second >= m)
					continue;
				if (vis[cur.first][cur.second])
					continue;
				vis[cur.first][cur.second] = true;
				q.push(make_pair(cur.first + 1, cur.second));
				q.push(make_pair(cur.first - 1, cur.second));
				q.push(make_pair(cur.first, cur.second + 1));
				q.push(make_pair(cur.first, cur.second - 1));
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
