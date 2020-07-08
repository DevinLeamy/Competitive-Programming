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
		ll n, k; cin >> n >> k;
		if (k == 3) {
			ll rem = n % 4;
			if (rem > 0) {
				cout << "Alice\n";
			} else {
				cout << "Bob\n";
			}
			continue;
		}
		if (n < k) {
			ll rem = n % 3;
			if (rem == 1 || rem == 2) {
				cout << "Alice\n";
			} else {
				cout << "Bob\n";
			}
		} else {
			if (n == k) {
				cout << "Alice\n";
				continue;
			}
			if (k % 3 == 0) {
				if ((n % (k+1)) % 3 == 0 && n % (k+1) != k) {
					cout << "Bob\n";
				} else {
					cout << "Alice\n";
				}
			} else {
				ll rem = n % 3;
				if (rem == 1 || rem == 2) {
					cout << "Alice\n";
				} else {
					cout << "Bob\n";
				}
			}
		}
		
	}
	return 0;
}
