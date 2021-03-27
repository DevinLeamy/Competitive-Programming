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
char _;

ll mod = 1000000007ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t, k; cin >> t >> k;

	vector<ll> dp(100002);
	for (int i = 0; i < k; i++)
		dp[i] = 1;
	for (int i = k; i <= 100000; i++) {
		dp[i] = (dp[i - 1] + dp[i - k]) % mod;
	}
	vector<ll> presum(100002);
	for (int i = 0; i <= 100000; i++) {
		presum[i + 1] = (dp[i] + presum[i]) % mod;
	}
	for (int i = 0; i < t; i++) {
		int a, b; cin >> a >> b;
		ll ans = (presum[b + 1] - presum[a] + mod) % mod;
		cout << ans << endl;
	}
	return 0;
}
