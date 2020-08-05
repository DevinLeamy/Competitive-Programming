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
		int n; cin >> n;
		int a;
		vector<int> vals(n);
		for (int i = 0; i < n; i++) { cin >> vals[i]; }
		if (n == 1) {
			cout << "YES" << endl;
			continue;
		}
		sort(vals.begin(), vals.end());
		bool works = true;
		for (int i = 1; i < n; i++) {
			if (vals[i] - vals[i-1] > 1) {
				works = false;
			}
		}
		if (works) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
