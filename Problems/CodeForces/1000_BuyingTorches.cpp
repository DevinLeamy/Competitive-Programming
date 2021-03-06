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
		ll x, y, k; cin >> x >> y >> k;
		ll ans = ((k * y) + (k - 1))/(x-1) + k;
		if (((k * y) + (k - 1))%(x-1) != 0) {
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
