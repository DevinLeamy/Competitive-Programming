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
	vector<int> dp(n + 1, INF/2);
	dp[n] = 0;
	for (int i = n; i >= 0; i--) {
		set<int> digits;
		string s = to_string(i);
		for (int j = 0; j < s.length(); j++) {
			digits.insert(s[j] - '0');
		}
		for (auto it = digits.begin(); it != digits.end(); it++) {
			if (i - *it >= 0)
				dp[i - *it] = min(dp[i - *it], dp[i] + 1);
		}
	}
	cout << dp[0];
	return 0;
}
