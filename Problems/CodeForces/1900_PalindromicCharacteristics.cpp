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

// Figure out how this works!!

ll cnt[5001];
ll dp[5001][5001] = {0};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	string s; cin >> s;
	int n = (int) s.length();

	for (int len = 1; len <= s.length(); ++len) {
		for (int i = 0; i <= s.size() - len; ++i) {
			if (len == 1)
				dp[i][len] = 1;
			else if (len == 2 && s[i] == s[i + 1])
				dp[i][len] = 2;
			else if (dp[i + 1][len - 2] && s[i] == s[i + len - 1])
				dp[i][len] = dp[i][len / 2] + 1;
			++cnt[dp[i][len]];
		}
	}
	for (int i = (int) s.size(); i > 0; --i)
		cnt[i] += cnt[i + 1];
	
	for (int i = 1; i <= n; i++)
		printf("%lld ", cnt[i]);
	printf("\n");
	return 0;
}
