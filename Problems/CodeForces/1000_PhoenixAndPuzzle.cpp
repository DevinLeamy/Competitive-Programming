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
	ll n; cin >> n;
	if (n % 2 == 1)
		return false;
	if (n % 2 == 0 && (ll) sqrt(n / 2) * (ll) sqrt(n / 2) == n / 2)
		return true;
	if (n % 4 == 0 && (ll) sqrt(n / 4) * (ll) sqrt(n / 4) == n / 4)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		if (solve())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
