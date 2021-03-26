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

ll cnt1, cnt2, x, y;

ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

ll lcm(ll a, ll b) {
	return (a * b) / gcd(a, b);
}

bool valid(ll largest) {
	if (x == y) {
		if (largest - largest / x >= cnt1 + cnt2)
			return true;
		return false;
	}
	ll untouchable = largest / lcm(x, y);
	ll f1_u = largest / y - untouchable;
	ll f2_u = largest / x - untouchable;
	
	ll f1_rem = max(0ll, cnt1 - f1_u);
	ll f2_rem = max(0ll, cnt2 - f2_u);
	
	ll overlap = largest - (f1_u + f2_u) - untouchable;
	if (overlap >= f1_rem + f2_rem)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	cin >> cnt1 >> cnt2 >> x >> y;
	
	ll left = 0, right = LINF;
	while (left < right) {
		ll mid = (left + right) / 2;
		if (valid(mid))
			right = mid;
		else
			left = mid + 1;
	}
	cout << left << endl;
	
	return 0;
}
