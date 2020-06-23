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
		if (n == 2 || (n % 2 == 1 && n != 1)) {
			cout << "Ashishgup" << endl;
		} else if (n == 1) {
			cout << "FastestFinger" << endl;
		} else {
			int odd = 0; int even = 0; ll temp = n;
			for (int i = 2; i <= sqrt(temp); i++) {
				while (n % i == 0) {
					if (i % 2 == 1) { odd++; }
					else { even++; }
					n = n/i;
				}
			}
			if (n > 2) { odd++; }
			if (odd == 0 || (even == 1 && odd == 1)) { cout << "FastestFinger" << endl; }
			else { cout << "Ashishgup" << endl; }
		}
		
	}
	return 0;
}
