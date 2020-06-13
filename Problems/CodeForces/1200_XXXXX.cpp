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
		int n, x, a, val = 0; cin >> n >> x;
		vector<int> index;
		for (int i = 1; i <= n; i++) {
			cin >> a; a %= x;
			val += a;
			if (a != 0) { index.pb(i); }
		}
		if (val % x != 0) { cout << n << endl; }
		else {
			if (index.size() == 0) { cout << -1 << endl; }
			else {
				cout << max(
						    max(index[0] - 1, n-(index[0])),
						    max(index[index.size() - 1] - 1, n-(index[index.size() - 1]))
					    )
				<< endl;
			}
		}
	}
	return 0;
}
