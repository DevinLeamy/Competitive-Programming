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

ll mod = 998244353ll;

ll add(ll a, ll b) {
	return (a + b) % mod;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<ll> dp(n + 1);
	
	// Calculate divisors
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			dp[j]++;
		}
	}
	dp[0] = dp[1] = 1;
	ll pre = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = add(dp[i], pre);
		pre = add(pre, dp[i]);
	}
	cout << dp[n] << endl;
	return 0;
}
