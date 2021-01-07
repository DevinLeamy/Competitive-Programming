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
		int n; cin >> n;
		vector<ll> even;
		vector<ll> odd;
		for (int i = 0; i < n; i++) {
			ll a; cin >> a;
			if (a % 2 == 0) even.pb(a);
			else odd.pb(a);
		}
		sort(even.rbegin(), even.rend());
		even.pb(-INF);
		sort(odd.rbegin(), odd.rend());
		odd.pb(-INF);
		
		ll al = 0;
		ll bob = 0;
		int id1 = 0;
		int id2 = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				if (even[id1] <= odd[id2]) {
					id2++;
				} else {
					al += even[id1];
					id1++;
				}
			} else {
				if (even[id1] >= odd[id2]) {
					id1++;
				} else {
					bob += odd[id2];
					id2++;
				}
			}
		}
		if (al > bob) {
			printf("Alice\n");
		} else if (bob > al) {
			printf("Bob\n");
		} else {
			printf("Tie\n");
		}
	}
	return 0;
}
