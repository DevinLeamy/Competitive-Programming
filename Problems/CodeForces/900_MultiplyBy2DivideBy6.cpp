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
		ll n; cin >> n;
		int three = 0;
		int two = 0;
		while (n % 2 == 0) {
			two++;
			n /= 2;
		}
		while (n % 3 == 0) {
			three++;
			n /= 3;
		}
		if (n != 1 || two > three) {
			cout << -1 << endl;
		} else {
			cout << three - two + three << endl;
		}
	}
	return 0;
}
