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
		for (int i = 0; i < n; i++) cin >> vals[i];
		vector<vector<int>> p1;
		int max = 0;
		for (int i = 0; i <= n; i++) {
			p1.pb(vector<int>(201));
		}
		for (int i = 0; i < n; i++) {
			p1[i+1][vals[i]]++;
			for (int j = 0; j <= 200; j++) {
				p1[i + 1][j] += p1[i][j];
				max = std::max(max, p1[i + 1][j]);
			}
		}
		for (int i = 0; i <= 200; i++) {
			int lp = 0;
			int rp = n;
			int next = 1;
			while (lp < rp) {
				while (lp < rp && p1[lp][i] < next) {
					lp++;
				}
				while (lp < rp && p1[n][i] - p1[rp][i] < next) {
					rp--;
				}
				if (p1[lp][i] == next && p1[n][i] - p1[rp][i] == next) {
					for (int j = 0; j <= 200; j++) {
						max = std::max(max, next*2 + p1[rp][j] - p1[lp][j]);
					}
				}
				next++;
			}
		}
		cout << max << endl;
	}
	return 0;
}
