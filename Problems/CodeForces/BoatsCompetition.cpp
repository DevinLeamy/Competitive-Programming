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
		vector<int> vals(n);
		for (int i = 0; i < n; i++) { cin >> vals[i]; }
		sort(vals.begin(), vals.end());
		vector<vector<int>> pos;
		for (int i = 0; i < n; i++) {
			pos.pb(vector<int>());
			for (int j = 0; j < n; j++) {
				pos[i].pb(vals[i] + vals[j]);
			}
		}
		int best = 0;
		for (int i = 1; i <= 2*n; i++) {
			vector<bool> taken(n);
			int cur = 0;
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (j == k) {
						continue;
					}
					if (pos[j][k] == i && !taken[j] && !taken[k]) {
						taken[j] = true;
						taken[k] = true;
						cur++;
					}
				}
			}
			best = max(best, cur);
		}
		cout << best << endl;
	}
	return 0;
}
