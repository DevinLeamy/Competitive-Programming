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
		int n; cin >> n;
		vector<bool> hard(n);
		for (int i = 0, a; i < n; i++) {
			cin >> a; hard[i] = a == 1;
		}
		vector<vector<ll>> dp(n, vector<ll>(4, INF));
		if (hard[0])
			dp[0][0] = 1;
		else
			dp[0][0] = 0;
		
		for (int i = 1; i < n; i++) {
			int add = hard[i]? 1 : 0;
			dp[i][1] = dp[i-1][0] + add;
			dp[i][2] = min(dp[i-1][1], dp[i-1][0]);
			dp[i][3] = dp[i-1][2];
			dp[i][0] = min(dp[i-1][3], dp[i-1][2]) + add;
		}
		cout << min(min(dp[n-1][0], dp[n-1][1]), min(dp[n-1][2], dp[n-1][3])) << endl;
	}
	return 0;
}
