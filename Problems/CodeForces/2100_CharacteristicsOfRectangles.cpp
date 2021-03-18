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
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, m; cin >> n >> m;
	vector<vector<int> > table(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> table[i][j];
	
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int val = min(table[i][0], table[j][0]);
			for (int k = 1; k < m; k++) {
				int new_row = min(table[i][k], table[j][k]);
				ans = max(ans, min(new_row, val));
				val = max(new_row, val);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
