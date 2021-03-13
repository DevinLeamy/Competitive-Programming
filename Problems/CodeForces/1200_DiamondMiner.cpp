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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		vector<ll> diamonds;
		vector<ll> miners;
		for (int i = 0; i < 2*n; i++) {
			ll x, y; cin >> x >> y;
			if (x == 0)
				miners.pb(abs(y));
			else
				diamonds.pb(abs(x));
		}
		sort(diamonds.rbegin(), diamonds.rend());
		sort(miners.rbegin(), miners.rend());
		double ans = 0;
		for (int i = 0; i < n; i++) {
			ans += sqrt(pow(miners[i], 2) + pow(diamonds[i], 2));
		}
		cout << ans << endl;
	}
	return 0;
}
