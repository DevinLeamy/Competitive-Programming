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
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		vector<PI> stars;
		vector<int> rows;
		vector<int> cols;
		vector<string> ans;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < n; j++) {
				if (s[j] == '*') {
					rows.pb(i);
					cols.pb(j);
				}
			}
			ans.pb(s);
		}
		if (rows[0] == rows[1]) {
			if (rows[0] == 0) {
				ans[1][cols[0]] = '*';
				ans[1][cols[1]] = '*';
			} else {
				ans[0][cols[0]] = '*';
				ans[0][cols[1]] = '*';
			}
		} else if (cols[0] == cols[1]) {
			if (cols[0] == 0) {
				ans[rows[0]][1] = '*';
				ans[rows[1]][1] = '*';
			} else {
				ans[rows[0]][0] = '*';
				ans[rows[1]][0] = '*';
			}
		} else {
			ans[rows[0]][cols[1]] = '*';
			ans[rows[1]][cols[0]] = '*';
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << endl;
		}
	}

	return 0;
}
