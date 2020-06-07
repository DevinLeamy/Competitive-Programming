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
		int n, a; cin >> n;
		vector<vector<int>> pre;
		pre.pb(vector<int>(26));
		int max = 1;
		for (int i = 1; i <= n; i++) {
			pre.pb(vector<int>(26));
			cin >> a; a--;
			pre[i][a]++;
			for (int j = 0; j < 26; j++) {
				pre[i][j] += pre[i-1][j];
				max = std::max(max, pre[i][j]);
			}
		}
		for (int z = 1; z <= n-1; z++) {
			for (int i = 1; i <= n-z-1; i++) {
				int bS = 0;
				int bM = 0;
				for (int j = 0; j < 26; j++) {
					int left = pre[z][j];
					int middle = pre[i+z][j] - pre[z][j];
					int right = pre[n][j] - pre[i+z][j];
					bM = std::max(bM, middle);
					bS = std::max(bS, min(left, right));
				}
				max = std::max(max, 2*bS + bM);
			}
		}
		cout << max << endl;
	}
	return 0;
}
