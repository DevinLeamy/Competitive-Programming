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
		ll n, x, y; cin >> n >> x >> y;
		ll worst = x + y - 1;
		ll best = (x + y - (n + 1));
		if (best == 0) { best = 2; }
		else if (best < 0) { best = 1; }
		else {
			best++;
			if (x < best || y > n-best) { best++; }
			if (x + y == n + best) { best++; }
		}
		cout << min(n, best) << " " << min(n, worst) << endl;
	}
	return 0;
}
