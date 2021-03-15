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
		ll n, k; cin >> n >> k;
		if (n % 2 == 0) {
			cout << ((k % n == 0)? n : k % n) << endl;
			continue;
		}
		if (k < n / 2 + 1) {
			cout << k << endl;
			continue;
		}
		ll rem = k % n;
		ll inc = (k - (n / 2 + 1)) / (n / 2) + 1;
		rem = (rem + inc) % n == 0? n : (rem + inc) % n;
		cout << rem << endl;
	}
	return 0;
}
