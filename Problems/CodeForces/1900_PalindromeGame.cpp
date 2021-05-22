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
#define view2(a, b) cout << "DEBUG: " << a << " " << b << endl;
using namespace std;
char _;

int solve() {
	int n; cin >> n;
	string s; cin >> s;
	int zeros = 0;
	int until_pal = 0;
	for (int i = 0; i < n/2; i++) {
		if (s[i] != s[n - 1 - i]) {
			until_pal++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			zeros++;
		}
	}
	if (until_pal == 0) {
		if (zeros % 2 == 0 || zeros == 1)
			return -1;
		else
			return 1;
	} else {
		if (zeros == 2 && until_pal == 1)
			return 0;
		else
			return 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int res = solve();
		if (res == 0) {
			cout << "DRAW\n";
		} else if (res == 1) {
			cout << "ALICE\n";
		} else {
			cout << "BOB\n";
		}
	}
	return 0;
}
