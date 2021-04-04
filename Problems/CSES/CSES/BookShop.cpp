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

int dp[100005];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, x; cin >> n >> x;
	vector<PI> vals(n);
	for (int i = 0; i < n; i++)
		cin >> vals[i].first;
	for (int i = 0; i < n; i++)
		cin >> vals[i].second;
	sort(vals.begin(), vals.end());
	for (int i = 0; i <= x; i++)
		dp[i] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = x - vals[i].first; j >= 0; j--) {
			dp[j + vals[i].first] = max(dp[j + vals[i].first], dp[j + vals[i].first - 1]);
			dp[j + vals[i].first] = max(dp[j + vals[i].first], dp[j] + vals[i].second);
		}
	}
	cout << dp[x] << "\n";
	return 0;
}
