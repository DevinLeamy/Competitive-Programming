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
		vector<int> vals(2*n);
		for (int i = 0; i < 2*n; i++) { cin >> vals[i]; }
		vector<int> subSet;
		int largest = vals[0];
		int index = 0;
		for (int i = 1; i < 2*n; i++) {
			if (vals[i] > largest) {
				subSet.pb(i - index);
				largest = vals[i];
				index = i;
			}
		}
		vector<bool> dp(n+1);
		dp[0] = true;
		for (int i = 0; i < subSet.size(); i++) {
			for (int j = n-subSet[i]; j >= 0; j--) {
				if (dp[j]) {
					dp[j+subSet[i]] = true;
				}
			}
		}
		if (dp[n]) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
