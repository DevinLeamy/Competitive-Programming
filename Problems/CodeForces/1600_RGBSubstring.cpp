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
	int q; cin >> q;
	vector<string> strings = {"RGB", "GBR", "BRG"};
	loop(q) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector<vector<int>> dp;
		dp.pb({0, 0, 0});
		int min = INF;
		for (int i = 0; i < n; i++) {
			dp.pb({0, 0, 0});
			for (int j = 0; j < 3; j++) {
				dp[i+1][j] = dp[i][j] + ((strings[j][i % 3] == s[i])? 0 : 1);
			}
			if (i >= k - 1) {
				for (int j = 0; j < 3; j++) {
					min = std::min(dp[i+1][j] - dp[i+1-k][j], min);
				}
			}
		}
		cout << min << "\n";
	}
	return 0;
}
