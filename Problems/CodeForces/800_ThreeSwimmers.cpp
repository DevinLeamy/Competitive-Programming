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
		ll p, a, b, c; cin >> p >> a >> b >> c;
		ll ta = (p % a == 0)? 0 : a - (p % a);
		ll tb = (p % b == 0)? 0 : b - (p % b);
		ll tc = (p % c == 0)? 0 : c - (p % c);
		cout << min(ta, min(tb, tc)) << endl;
	}
	return 0;
}
