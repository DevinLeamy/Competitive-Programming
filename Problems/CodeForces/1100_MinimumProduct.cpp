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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		ll a, b, x, y, n; cin >> a >> b >> x >> y >> n;
		ll a1 = a;
		ll b1 = b;
		ll n1 = n;
		ll min = LINF;
		ll rem = std::min(a - x, n);
		n -= rem;
		a -= rem;
		b = max(y, b-n);
		ll rem2 = std::min(b1 - y, n1);
		n1 -= rem2;
		b1 -= rem2;
		a1 = max(x, a1-n1);
		min = std::min(a*b, a1 * b1);
		cout << min << endl;
	}
	return 0;
}
