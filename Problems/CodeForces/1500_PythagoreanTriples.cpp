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
		ll n; cin >> n;
		ll cnt = 0;
		for (ll i = 1; i * i <= 2 * n; i++) {
			if ((i * i - 1) % 2 == 0) {
				ll a = i;
				ll b = (a * a - 1) / 2;
				if (a * a - b <= n && b > 0 && b < n) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
