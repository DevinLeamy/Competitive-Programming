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
	int n; cin >> n;
	ll a, best = 0;
	vector<ll> vals;
	for (int i = 0; i < n; i++) { cin >> a; vals.pb(a); }
	if (n == 1) { cout << vals[0] << endl; return 0; }
	else if (n == 2) { cout << (vals[0] | vals[1]) << endl; return 0; }
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				best = max(best, (vals[i] | vals[j] | vals[k]));
			}
		}
	}
	cout << best << endl;
	return 0;
}
