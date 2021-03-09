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

bool solve() {
	int n, U, R, D, L; cin >> n >> U >> R >> D >> L;
	int u = U, r = R, d = D, l = L;
	for (int mask = 0; mask <= (1 << 4); mask++) {
		bool valid = true;
		if (1 & (mask >> 0)) {
			U--;
			R--;
		}
		if (1 & (mask >> 1)) {
			U--;
			L--;
		}
		if (1 & (mask >> 2)) {
			L--;
			D--;
		}
		if (1 & (mask >> 3)) {
			D--;
			R--;
		}
		valid &= (0 <= U && U <= n - 2) &&
				 (0 <= R && R <= n - 2) &&
				 (0 <= L && L <= n - 2) &&
				 (0 <= D && D <= n - 2);
		if (valid)
			return true;
		U = u;
		R = r;
		D = d;
		L = l;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	while (t--) {
		if (solve())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
