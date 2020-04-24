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
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define PL pair<long long, long long>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

ll dp[101][101][2]; //How many paths of length i have a weight of j
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k, d; cin >> n >> k >> d;
	ll mod = 1000000007;

	for (int i = 1; i <= k; i++) {
		if (i >= d) {
			dp[0][i][1] = 1;
		} else {
			dp[0][i][0] = 1;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			for (int l = 1; l <= k; l++) {
				if (j + l <= n) {
					if (l >= d) {
						dp[i][j+l][1] += dp[i-1][j][0];
						dp[i][j+l][1] += dp[i-1][j][1];
					} else {
						dp[i][j+l][1] += dp[i-1][j][1];
						dp[i][j+l][0] += dp[i-1][j][0];
					}
					dp[i][j+l][0] %= mod;
					dp[i][j+l][1] %= mod;
					
				}
			}
		}
	}
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += dp[i][n][1];
		sum %= mod;
	}
	cout << sum;
	
	return 0;
}
