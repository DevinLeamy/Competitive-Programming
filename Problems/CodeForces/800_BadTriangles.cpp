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
		int n; cin >> n;
		vector<ll> vals(n);
		for (int i = 0; i < n; i++) cin >> vals[i];
		ll a = vals[n-1];
		ll b = vals[1];
		ll c = vals[0];
		if (a + b <= c || a + c <= b || b + c <= a) {
			cout << 1 << " " << 2 << " " << n << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
