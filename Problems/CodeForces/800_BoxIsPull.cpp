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
		ll x1, x2, y1, y2;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		if (x1 - x2 == 0) {
			cout << abs(y1 - y2) << endl;
		} else if (y2 - y1 == 0) {
			cout << abs(x1 - x2) << endl;
		} else {
			cout << abs(x1 - x2) + abs(y1 - y2) + 2 << endl;
		}
	}
	return 0;
}
