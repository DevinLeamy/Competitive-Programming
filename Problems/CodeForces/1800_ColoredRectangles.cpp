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

ll dp[202][202][202];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll r, g, b, a; cin >> r >> g >> b;
	vector<ll> red;
	vector<ll> blue;
	vector<ll> green;
	for (int i = 0; i < r; i++) {
		cin >> a;
		red.pb(a);
	}
	for (int i = 0; i < g; i++) {
		cin >> a;
		green.pb(a);
	}
	for (int i = 0; i < b; i++) {
		cin >> a;
		blue.pb(a);
	}
	ll max = 0;
	sort(red.rbegin(), red.rend());
	sort(blue.rbegin(), blue.rend());
	sort(green.rbegin(), green.rend());
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= b; j++) {
			for (int k = 0; k <= g; k++) {
				if (i != r && j != b) {
					dp[i+1][j+1][k] = std::max(dp[i+1][j+1][k], dp[i][j][k] + red[i] * blue[j]);
				}
				if (j != b && k != g) {
					dp[i][j+1][k+1] = std::max(dp[i][j+1][k+1], dp[i][j][k] + green[k] * blue[j]);
				}
				if (i != r && k != g) {
					dp[i+1][j][k+1] = std::max(dp[i+1][j][k+1], dp[i][j][k] + red[i] * green[k]);
				}
				max = std::max(max, dp[i+1][j+1][k]);
				max = std::max(max, dp[i][j+1][k+1]);
				max = std::max(max, dp[i+1][j][k+1]);
			}
		}
	}
	cout << max << endl;
	return 0;
}
