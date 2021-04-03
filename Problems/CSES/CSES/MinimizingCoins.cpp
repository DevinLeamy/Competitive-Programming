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
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	vector<int> dp(x + 1, INF);
	dp[0] = 0;
	for (int i = 1; i <= x; i++) {
		for (int coin : coins) {
			if (i - coin >= 0 && dp[i - coin] != INF) {
				dp[i] = min(dp[i], 1 + dp[i - coin]);
			}
		}
	}
	if (dp[x] == INF)
		cout << -1 << endl;
	else
		cout << dp[x] << endl;
	return 0;
}
