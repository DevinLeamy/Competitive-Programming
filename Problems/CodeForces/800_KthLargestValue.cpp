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
	int n, q; cin >> n >> q;
	vector<bool> on(n);
	int ones = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		on[i] = a == 1;
		if (on[i]) ones++;
	}
	for (int i = 0; i < q; i++) {
		int t, idx; cin >> t >> idx;
		if (t == 1) {
			on[idx - 1] = !on[idx - 1];
			if (!on[idx - 1]) {
				ones--;
			} else {
				ones++;
			}
		} else {
			if (ones >= idx) {
				cout << 1 << endl;
			} else {
				cout << 0 << endl;
			}
		}
	}
	
	return 0;
}
