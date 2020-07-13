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
		int n, x; cin >> n >> x;
		vector<ll> vals(n);
		for (int i = 0; i < n; i++) { cin >> vals[i]; }
		sort(vals.begin(), vals.end());
		int count = 0;
		int teamC = 0;
		ll min = 0;
		for (int i = n-1; i >= 0; i--) {
			if (teamC * min < x) {
				teamC++;
				min = vals[i];
			} else {
				count++;
				teamC = 1;
				min = vals[i];
			}
		}
		if (teamC * min >= x) {
			count++;
		}
		cout << count << endl;
	}
	return 0;
}
