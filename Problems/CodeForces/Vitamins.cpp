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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<PI> vals(n);
	vector<int> dp(8, INF);
	for (int i = 0; i < n; i++) {
		int a; string s; cin >> a >> s;
		pair<int, int> vit;
		vit.first = a;
		for (int j = 0; j < (int) s.length(); j++)
			vit.second += pow(2, (s[j] - 'A'));
			
		vals[i] = vit;
		dp[vit.second] = min(dp[vit.second], vit.first);
	}
	for (int i = 0; i < n; i++) {
		int cost = vals[i].first;
		int mask = vals[i].second;
		for (int j = 0; j < (1 << 3); j++) {
			if (dp[j] == INF)
				continue;
			dp[j | mask] = min(dp[j | mask], dp[j] + cost);
		}
	}
	cout << ((dp[7] == INF)? -1 : dp[7]) << endl;
	return 0;
}
