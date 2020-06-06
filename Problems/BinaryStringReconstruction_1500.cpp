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

string ans;
int n;
bool backtracking(int n2, int n1, int n0, int pos, int last, string val) {
	if (n2 + n1 + n0 == 0 && pos == n) {
		ans = val;
		return true;
	}
	if (pos == 0) {
		val[0] = '0';
		if (backtracking(n2, n1, n0, pos + 1, 0, val)) {
			return true;
		}
		val[0] = '1';
		if (backtracking(n2, n1, n0, pos + 1, 1, val)) {
			return true;
		}
	}
	if (last == 0) {
		if (n0 > 0) {
			val[pos] = '0';
			if (backtracking(n2, n1, n0 - 1, pos + 1, 0, val)) {
				return true;
			}
			val[pos] = '*';
		}
		if (n1 > 0) {
			val[pos] = '1';
			if (backtracking(n2, n1 - 1, n0, pos + 1, 1, val)) {
				return true;
			}
			val[pos] = '*';
		}
	} else {
		if (n2 > 0) {
			val[pos] = '1';
			if (backtracking(n2 - 1, n1, n0, pos + 1, 1, val)) {
				return true;
			}
			val[pos] = '*';
		}
		if (n1 > 0) {
			val[pos] = '0';
			if (backtracking(n2, n1 - 1, n0, pos + 1, 0, val)) {
				return true;
			}
			val[pos] = '*';
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		n = n1 + n2 + n3 + 1;
		string val = "";
		for (int i = 0; i < n; i++) { val += "0"; }
		backtracking(n3, n2, n1, 0, 0, val);
		cout << ans << endl;
		
	}
	return 0;
}
