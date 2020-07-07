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


int n, m;
int nei(int row, int col) {
	row %= n-1;
	col %= m-1;
	if (row == 0 && col == 0) { return 2; }
	else if (row == 0 || col == 0) { return 3; }
	else { return 4; }
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		cin >> n >> m;
		int a;
		vector<vector<int>> vals;
		bool works = true;
		for (int i = 0; i < n; i++) {
			vals.pb(vector<int>());
			for (int j = 0; j < m; j++) {
				cin >> a;
				vals[i].pb(a);
				if (nei(i, j) < a) { works = false; }
			}
		}
		if (!works) { cout << "NO" << endl; }
		else {
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << nei(i, j) << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}
