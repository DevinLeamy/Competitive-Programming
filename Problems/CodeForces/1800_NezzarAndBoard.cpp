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

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

bool solve() {
	int n; ll k; cin >> n >> k;
	vector<ll> vals(n);
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	
	sort(vals.begin(), vals.end());
	
	ll g = 0;
	for (int i = 1; i < n; i++)
		g = gcd(g, vals[i] - vals[0]);
	if ((k - vals[0]) % g == 0)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		if (solve())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
