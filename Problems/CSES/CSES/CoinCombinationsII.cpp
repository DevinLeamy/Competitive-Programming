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
	int n, x; cin >> n >> x;
	ll mod = 1000000007ll;
	vector<int> coins(n);
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	sort(coins.begin(), coins.end());
	vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - coins[i - 1] < 0)
				continue;
			dp[i][j] = (dp[i][j] + dp[i][j - coins[i - 1]]) % mod;
		}
	}
	
	printf("%d\n", dp[n][x]);
	return 0;
}
