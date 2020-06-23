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
		vector<vector<bool>> on(n);
		for (int i = 0; i < n; i++) {
			string line; cin >> line;
			for (int j = 0; j < n; j++) {
				on[i].pb(line[j] == '1');
			}
		}
		bool pos = true;
		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < n-1; j++) {
				if (on[i][j]) {
					if (!on[i+1][j] && !on[i][j+1]) {
						pos = false;
					}
				}
			}
		}
		if (pos) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	return 0;
}
