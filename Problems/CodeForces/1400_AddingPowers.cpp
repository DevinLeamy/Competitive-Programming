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
		vector<ll> vals(n);
		vector<int> freq(100);
		bool works = true;
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
			if (vals[i] != 0) {
				for (int j = log(10000000000000000ll)/log(k); j >= 0; j--) {
					if (vals[i] >= (ll)pow(k, j)) {
						freq[j]++;
						vals[i] -= (ll)pow(k, j);
					}
				}
				if (vals[i] != 0) {
					works = false;
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			int f = freq[i];
			if (f > 0 && f != 1) {
				works = false;
			}
		}
		
		cout << (works? "YES":"NO") << endl;
	}
	return 0;
}
