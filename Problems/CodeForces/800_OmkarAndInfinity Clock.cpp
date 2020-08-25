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
		int n; ll k; cin >> n >> k;
		ll max = -LINF;
		ll min = LINF;
		vector<ll> vals;
		for (int i = 0; i < n; i++) {
			ll a; cin >> a;
			max = std::max(a, max);
			min = std::min(a, min);
			vals.pb(a);
		}
		for (int i = 0; i < n; i++) {
			cout << (k%2 == 1? (max - vals[i])*2: max - min) - (max - vals[i]) << " ";
		}
		cout << endl;
	}
	return 0;
}
