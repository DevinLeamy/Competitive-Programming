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
	int n; cin >> n;
	vector<ll> sph(n);
	for (int i = 0; i < n; i++) cin >> sph[i];
	if (n == 1) {
		cout << 0 << "\n" << sph[0] << endl;
		return 0;
	} else if (n == 2) {
		cout << 0 << "\n" << sph[0] << " " << sph[1] << endl;
		return 0;
	}
	sort(sph.begin(), sph.end());
	vector<ll> ans(n);
	int cur = (int) sph.size()-1;
	for (int i = 0; i < n; i += 2) {
		ans[i] = sph[cur];
		cur--;
	}
	int cur2 = n - (1 + n%2);
	if (n % 2 == 0) {
		// thus the smallest sph. does not end up rightmost (and not cheapest)
		ans[cur2] = sph[cur];
		cur--;
		cur2 -= 2;
	}
	int total = 0;
	for (int i = 0; i <= cur; i++) {
		ans[cur2] = sph[i];
		if (cur2 != n-1 && ans[cur2-1] > ans[cur2] && ans[cur2+1] > ans[cur2]) total++;
		cur2 -= 2;
	}
	cout << total << endl;
	for (ll val : ans) {
		cout << val << " ";
	}
	return 0;
}
