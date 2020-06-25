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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		ll a;
		vector<ll> vals(n+1);
		for (int i = 1; i <= n; i++) { cin >> a; vals[i] = a; }
		vector<int> dp(n+1);
		for (int i = 1; i <= n; i++) { dp[i] = 1; }
		int max = 1;
		for (int i = n; i >= 1; i--) {
			ll val = vals[i];
			for (int j = 1; j <= sqrt(i); j++) {
				if (i % j == 0) {
					if (vals[i/j] < val) {
						dp[i/j] = std::max(dp[i/j], dp[i] + 1);
						max = std::max(dp[i/j], max);
					}
					if (vals[j] < val) {
						dp[j] = std::max(dp[j], dp[i] + 1);
						max = std::max(dp[j], max);
					}
				}
			}
		}
		cout << max << endl;
		
	}
	return 0;
}
