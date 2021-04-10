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

vector<vector<bool>> solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	if (a * n != m * b)
		return {};
	vector<vector<bool>> res(n, vector<bool>(m));
	vector<PI> cnts(m);
	for (int i = 0; i < m; i++)
		cnts[i] = {b, i};
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a; j++) {
			res[i][cnts[j].second] = true;
			cnts[j].first--;
		}
		sort(cnts.rbegin(), cnts.rend());
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		vector<vector<bool>> res = solve();
		if (res.empty()) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (int i = 0; i < res.size(); i++) {
				for (bool val : res[i]) {
					cout << ((val)? 1 : 0);
				}
				cout << endl;
			}
		}
	}
	return 0;
}
