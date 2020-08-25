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
		ll a, b, c; cin >> a >> b >> c;
		ll min = std::min(a, std::min(b, c));
		if (b == c && a <= c) {
			cout << "YES" << endl;
			cout << min << " " << min << " " << b << endl;
		} else if (a == b && c <= a) {
			cout << "YES" << endl;
			cout << a << " " << min << " " << min << endl;
		} else if (a == c && b <= a) {
			cout << "YES" << endl;
			cout << min << " " << a << " " << min << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
