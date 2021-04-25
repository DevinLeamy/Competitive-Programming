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
#define view2(a, b) cout << "DEBUG: " << a << " " << b << endl;
using namespace std;
char _;

int n, m, k;
int MAXN = 505;
int MAXK = 25;
vector<vector<vector<ll>>> dp(MAXN, vector<vector<ll>>(MAXN, vector<ll>(MAXK, -1)));
vector<vector<PI>> grid(MAXN, vector<PI>(MAXN)); // right, down
vector<vector<ll>> ans(MAXN, vector<ll>(MAXN)); 
ll dp_bfs(int i, int j, int steps) {
	if (i < 0 || i >= n || j < 0 || j >= m)
		return LINF / 2ll;
	if (steps == 0)
		dp[i][j][steps] = 0;
	
	if (dp[i][j][steps] != -1)
		return dp[i][j][steps];
	
	ll min_val = LINF;
	if (i != 0)
		min_val = min(min_val, dp_bfs(i - 1, j, steps - 1) + grid[i - 1][j].second); // Up
	if (i != n - 1)
		min_val = min(min_val, dp_bfs(i + 1, j, steps - 1) + grid[i][j].second); // Down
	if (j != 0)
		min_val = min(min_val, dp_bfs(i, j - 1, steps - 1) + grid[i][j - 1].first); // Left
	if (j != m - 1)
		min_val = min(min_val, dp_bfs(i, j + 1, steps - 1) + grid[i][j].first); // Right
	dp[i][j][steps] = min_val;
	return dp[i][j][steps];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			int a; cin >> a;
			grid[i][j].first = a;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			grid[i][j].second = a;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp_bfs(i, j, k / 2);
			ans[i][j] = (k & 1)? -1 : dp[i][j][k / 2] * 2ll;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
