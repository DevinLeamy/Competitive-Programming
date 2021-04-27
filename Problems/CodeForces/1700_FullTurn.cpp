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

ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

PL vect(ll x_i, ll y_i, ll x_l, ll y_l) {
	ll x1 = x_i - x_l;
	ll y1 = y_i - y_l;
	
	if (x1 == 0 && y1 == 0)
		return make_pair(0, 0);
	
	ll g = gcd(min(abs(x1), abs(y1)), max(abs(x1), abs(y1)));
	return make_pair(x1 / g, y1 / g);
}

ll solve() {
	int n; cin >> n;
	vector<vector<ll>> vals(n);
	for (int i = 0; i < n; i++) {
		vector<ll> pos(4);
		for (int j = 0; j < 4; j++)
			cin >> pos[j];
		vals[i] = pos;
	}
	
	ll cnt = 0;
	map<PL, int> norms;
	for (int i = 0; i < n; i++) {
		PL norm = vect(vals[i][0], vals[i][1], vals[i][2], vals[i][3]);
		PL inv = make_pair(-1ll * norm.first, -1ll * norm.second);
		if (norms.count(inv) != 0)
			cnt += norms[inv];
		norms[norm]++;
	}
	
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		printf("%lld\n", solve());
	}
	return 0;
}
