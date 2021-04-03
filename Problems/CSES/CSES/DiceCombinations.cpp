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
	int n; cin >> n;
	ll mod = 1000000007ll;
	vector<ll> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = max(0, i - 6); j < i; j++) {
			dp[i] = (dp[i] + dp[j]) % mod;
		}
	}
	cout << dp[n] << endl;
	return 0;
}
