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

ll maxV = 999983ll * 999983ll;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		vector<int> vals(n);
		int max = 0;
		bool flag = true;
		for (int i = 0; i < n; i++) { cin >> vals[i]; max = std::max(max, vals[i]); }
		vector<int> maxN(1000000);
		for (int i = 0; i < n; i++) {
			for (ll j = 2; j * j <= vals[i]; j++) {
				int count = 0;
				while (vals[i] % j == 0) {
					vals[i] /= j;
					count++;
				}
				maxN[j] = std::max(maxN[j], count);
			}
			if (vals[i] != 1) {
				maxN[vals[i]] = std::max(maxN[vals[i]], 1);
			}
		}
		ll val = 1;
		ll divisors = 1;
		for (int i = 1; i < 1000000; i++) {
			val *= pow(i, maxN[i]);
			divisors *= (maxN[i] + 1);
			if (val > maxV) {
				flag = false;
				break;
			}
		}
		if (max >= val && flag) {
			for (int i = 1; i < 1000000; i++) {
				if (maxN[i] > 0) {
					divisors /= (maxN[i] + 1);
					val *= i;
					divisors *= (maxN[i] + 2);
				}
			}
		}
		if (flag && divisors - 2 == n) {
			cout << val << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
