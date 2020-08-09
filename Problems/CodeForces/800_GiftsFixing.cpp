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
		vector<ll> a(n);
		vector<ll> b(n);
		ll minO = LINF;
		ll minC = LINF;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			minC = min(minC, a[i]);
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			minO = min(minO, b[i]);
		}
		ll best = LINF;
		if (n == 1) {
			cout << "0" << endl;
			continue;
		}
		ll cur = 0;
		for (int i = 0; i < n; i++) {
			cur += max(abs(a[i] - minC), abs(b[i] - minO));
		}
		cout << cur << endl;
	}
	return 0;
}
