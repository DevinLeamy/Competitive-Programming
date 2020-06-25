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
		int n, a, rem = 0, count = 0; cin >> n;
		vector<int> vals;
		for (int i = 0; i < n; i++) { cin >> a; vals.pb(a); }
		sort(vals.begin(), vals.end());
		for (int i = 0; i < n; i++) {
			int cur = vals[i];
			rem++;
			while (i != n-1 && vals[i+1] == cur) {
				rem++;
				i++;
			}
			count += rem / vals[i];
			rem %= vals[i];
		}
		cout << count << "\n";
	}
	return 0;
}
