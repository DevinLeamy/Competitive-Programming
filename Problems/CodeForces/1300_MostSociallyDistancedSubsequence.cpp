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
		int n, p; cin >> n;
		vector<bool> take(n); vector<int> vals;
		for (int i = 0; i < n; i++) { cin >> p; take[i] = true; vals.pb(p); }
		int count = n;
		for (int i = 1; i < n-1; i++) {
			if (abs(vals[i] - vals[i-1]) + abs(vals[i+1] - vals[i]) == abs(vals[i+1] - vals[i-1])) {
				take[i] = false;
				count--;
			}
		}
		cout << count << endl;
		for (int i = 0; i < n; i++) {
			if (take[i]) { cout << vals[i] << " "; }
		}
		cout << "\n";
	}
	return 0;
}
