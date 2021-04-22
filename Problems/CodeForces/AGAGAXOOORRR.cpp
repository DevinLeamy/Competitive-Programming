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

bool solve() {
	int n; cin >> n;
	vector<ll> vals(n);
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}
	for (int p = 1; p < n; p++) {
		ll x = 0;
		for (int j = 0; j < p; j++)
			x ^= vals[j];
		ll cur = 0;
		ll cur2 = 0;
		for (int j = p; j < n; j++) {
			if (cur == x) {
				cur = 0;
				cur2++;
			}
			cur ^= vals[j];
		}
		if (cur == x) cur2++;
		if ((cur == x || cur == 0) && cur2 > 0)
			return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		if (solve()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
