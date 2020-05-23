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
#define LINF 9123372036854775807ll
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define PL pair<long long, long long>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

int n, m;
ll vals[100][100];
ll dp[100][100];
ll dist[100][100];

ll cost(ll first) {
	ll cost[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cost[i][j] = vals[i][j] - (first + dist[i][j]);
			dp[i][j] = LINF;
		}
	}
	dp[0][0] = vals[0][0] - first;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if ((i == 0 && j == 0) || cost[i][j] < 0) continue;
			if (j != 0 && cost[i][j-1] >= 0) {
				dp[i][j] = min(dp[i][j], dp[i][j-1] + cost[i][j]);
			}
			if (i != 0 && cost[i-1][j] >= 0) {
				dp[i][j] = min(dp[i][j], dp[i-1][j] + cost[i][j]);
			}
		}
	}
	return dp[n-1][m-1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		cin >> n >> m;
		ll val;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> val;
				vals[i][j] = val;
				dist[i][j] = i + j;
			}
		}
		if (n == 1 && m == 1) {
			cout << 0 << endl;
			continue;
		}
		ll best = LINF;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				best = min(best, cost(vals[i][j] - dist[i][j]));
			}
		}
		cout << best << endl;
		
	}
	return 0;
}
