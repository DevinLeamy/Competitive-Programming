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

bool a[61][61];

int solve(int n, int m) {
	bool not_pos = true;
	bool only_a = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j])
				not_pos = false;
			else
				only_a = false;
		}
	}
			
	// No A's
	if (not_pos)
		return -1;
	
	// Done
	if (only_a)
		return 0;
	
	pair<bool, bool> completeR = {true, true};
	pair<bool, bool> completeC = {true, true};
	for (int i = 0; i < m; i++) {
		completeR.first &= a[0][i];
		completeR.second &= a[n - 1][i];
	}
	for (int i = 0; i < n; i++) {
		completeC.first &= a[i][0];
		completeC.second &= a[i][m - 1];
	}
	
	// Full side
	if (completeR.first || completeR.second || completeC.first || completeC.second)
		return 1;
	
	// Corner or full row/col
	if (a[0][m-1] || a[0][0] || a[n-1][0] || a[n-1][m-1])
		return 2;
	for (int i = 0; i < n; i++) {
		bool complete = true;
		for (int j = 0; j < m; j++) {
			complete &= a[i][j];
		}
		if (complete)
			return 2;
	}
	for (int j = 0; j < m; j++) {
		bool complete = true;
		for (int i = 0; i < n; i++) {
			complete &= a[i][j];
		}
		if (complete)
			return 2;
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i][0] || a[i][m-1])
			return 3;
	}
	for (int j = 0; j < m; j++) {
		if (a[0][j] || a[n-1][j])
			return 3;
	}
	
	return 4;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < m; j++) {
				a[i][j] = s[j] == 'A';
			}
		}
		int res = solve(n, m);
		if (res == -1)
			cout << "MORTAL" << endl;
		else
			cout << res << endl;
	}
	return 0;
}
