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

string solve() {
	int n; cin >> n;
	vector<ll> vals(n);
	vector<int> cnts(50);
	// if k_moves is odd, k picks last
	for (int i = 0; i < n; i++) {
		ll val; cin >> val;
		vals[i] = val;
		int idx = 0;
		while (val != 0) {
			if (val & 1) {
				cnts[idx]++;
			}
			val /= 2;
			idx++;
		}
	}
	for (int i = 0; i < 50; i++) {
		if (cnts[i] % 2 == 0)
			cnts[i] = 0;
	}
	for (int i = 49; i >= 0; i--) {
		if (cnts[i] == 0)
			continue;
		if (cnts[i] % 4 == 3 && (n - cnts[i]) % 2 == 0)
			return "LOSE";
		else
			return "WIN";
	}
	return "DRAW";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		cout << solve() << endl;
	}
	return 0;
}
