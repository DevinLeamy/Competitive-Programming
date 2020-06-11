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
	int n; ll a, count = 0; cin >> n;
	vector<int> val(n+1);
	vector<PL> pre;
	pre.pb({0, 0});
	for (int i = 0; i < n; i++) { cin >> a; pre.pb({pre[i].first + a, i + 1}); }
	sort(pre.begin(), pre.end());
	ll last = pre[0].first;
	int mark = 1;
	int zero = 0;
	for (int i = 0; i <= n; i++) {
		if (pre[i].first != last) { mark++; }
		val[pre[i].second] = mark;
		if (pre[i].first == 0) {
			zero = mark;
		}
		last = pre[i].first;
	}
	val[0] = zero;
	vector<bool> found(mark+1);
	int back = 0;
	for (int i = 0; i <= n; i++) {
		int v = val[i];
		if (found[v] && v != 0) {
			while(val[back] != v) {
				found[val[back]] = false;
				back++;
			}
			back++;
		}
		found[v] = true;
		count += (i - back);
	}
	cout << count << endl;
	return 0;
}
