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
int n, k;
ll dp[1005][1005];
ll search(int pos, int d) {
	if (pos >= n)
		return 0ll;
	if (d == 1)
		return 0ll;
	if (dp[pos][d] != -1)
		return dp[pos][d];
	ll res = search(n - pos, d - 1) + 1;
	if (pos != n - 1)
		res += search(pos + 1, d);
	res %= mod;
	dp[pos][d] = res;
	return res;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			dp[i][j] = -1;
		}
	}
	loop(t) {
		cin >> n >> k;
		for (int i = 0; i <= 1000; i++) {
			for (int j = 0; j <= 1000; j++) {
				dp[i][j] = -1;
			}
		}
		cout << (search(0, k) + 1)%mod << endl;
	}
	return 0;
}
