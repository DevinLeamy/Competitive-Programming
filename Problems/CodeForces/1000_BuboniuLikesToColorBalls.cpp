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
		ll a, b, c, w; cin >> a >> b >> c >> w;
		int sum = (a%2) + (b%2) + (c%2);
		if (w % 2 == 0) {
			if (sum == 3 || sum == 0 || sum == 1) cout << "YES" << endl;
			else cout << "NO" << endl;
		} else {
			if (sum == 3 || sum == 0 || (sum == 2 && a > 0 && b > 0 && c > 0)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}
