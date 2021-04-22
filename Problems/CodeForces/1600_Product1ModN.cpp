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

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<ll> pos;
	ll cur = 1;
	for (int i = 1; i < n; i++) {
		if (gcd(i, n) == 1) {
			pos.pb(i);
			cur = (cur * i) % n;
		}
	}
	cout << pos.size() - (cur > 1) << endl;
	for (ll val : pos) {
		if (val != cur || val == 1)
			cout << val << " ";
	}
	cout << endl;
	return 0;
}
