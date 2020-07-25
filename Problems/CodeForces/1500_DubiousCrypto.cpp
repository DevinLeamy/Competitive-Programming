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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		ll l, r, m; cin >> l >> r >> m;
		for (ll i = l; i <= r; i++) {
			if (m % i <= (r - l) && m - m%i > 0 && l + m%i <= r) {
				cout << i << " " << l + m%i << " " << l << endl;
				break;
			} else if (i - m%i <= (r - l) && l + (i - m%i) <= r) {
				cout << i << " " << l << " " << l + (i - m%i) << endl;
				break;
			}
		}
		
	}
	return 0;
}
