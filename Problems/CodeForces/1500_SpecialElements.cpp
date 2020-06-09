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
		int n, a, count = 0; cin >> n;
		vector<int> pre; pre.pb(0);
		vector<int> found(n+1);
		for (int i = 0; i < n; i++) { cin >> a; pre.pb(pre[i] + a); found[a]++; }
		for (int i = 0; i < n; i++) {
			for (int j = i + 2; j <= n; j++) {
				int val = pre[j] - pre[i];
				if (val > n) { break; }
				if (found[val]) {
					count += found[val];
					found[val] = 0;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}
