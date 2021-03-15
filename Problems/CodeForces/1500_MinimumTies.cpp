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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		vector<int> wins(n);
		if (n % 2 == 1) {
			int w = (n - 1)/2;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (wins[i] != w) {
						cout << "1 ";
						wins[i]++;
					} else {
						wins[j]++;
						cout << "-1 ";
					}
				}
			}
			cout << endl;
		} else {
			vector<vector<int>> res(n, vector<int>(n, -2));
			for (int i = 0; i < n; i++) {
				if (i % 2 == 0)
					res[i][i+1] = 0;
				
				for (int j = 0; j < n; j++) {
					if (j == i || res[i][j] != -2 || res[j][i] != -2) continue;
					int sml = min(i, j);
					int lgr = max(i, j);
					res[sml][lgr] = (j % 2 == i % 2)? 1 : -1;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++)
					if (res[i][j] != -2) {
						cout << res[i][j] << " ";
					}
			}
			cout << endl;
		}
	}
	return 0;
}
