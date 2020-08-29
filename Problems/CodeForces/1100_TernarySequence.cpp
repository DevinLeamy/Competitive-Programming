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
		ll x1, x2, y1, y2, z1, z2;
		cin >> x1 >> y1 >> z1;
		cin >> x2 >> y2 >> z2;
		ll temp = z2;
		z2 -= min(z2, x1);
		x1 -= min(temp, x1);
		y1 -= min(y1, x2);
		cout << min(z1, y2) * 2 + min(z2, y1) * -2 << endl;
	}
	return 0;
}
