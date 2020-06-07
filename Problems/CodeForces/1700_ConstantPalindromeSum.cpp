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
		int n, k, a; cin >> n >> k;
		vector<int> pre(4*k);
		vector<int> vals;
		for (int i = 0; i < n; i++) { cin >> a; vals.pb(a); }
		for (int i = 0; i < n/2; i++) {
			int a = vals[i], b = vals[n - 1 - i];
			int minOne = min(a, b) + 1;
			int sum = a + b;
			int maxOne = max(a, b) + k;
			pre[sum]--;
			pre[sum + 1]++;
			pre[maxOne + 1]++;
			if (minOne - 1 != 1) {
				pre[2] += 2;
				pre[minOne]--;
			} else {
				pre[2]++;
			}
		}
		int cur = pre[2];
		int min = pre[2];
		for (int i = 3; i <= 2*k; i++) {
			cur += pre[i];
			min = std::min(cur, min);
		}
		cout << min << endl;
	}
	return 0;
}
