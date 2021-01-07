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

ll n, m, a, b;

bool valid(int cnt, vector<ll> &vals) {
	if (cnt == 0) return true;
	if (cnt > vals.size()) return false;
	if (cnt < 0) return false;
	
	ll dist_p = abs(a - b);
	ll dist_e = (a < b)? a - 1: n - a;
	if (cnt >= dist_p)
		return false;
	ll time = cnt + dist_e;
	dist_p -= cnt;
	time += dist_p - 1;
	for (int i = cnt - 1; i >= 0; i--) {
		if (vals[i] > time) {
			return false;
		}
		time--;
	}
	return true;
}

int bs(int l, int r, vector<ll> &vals) {
	if (r - 1 <= l)
		return min(l, r);
	int mid = (r + l) / 2;
	if (valid(mid, vals)) {
		return bs(mid, r, vals);
	} else {
		return bs(l, mid - 1, vals);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		cin >> n >> m >> a >> b;
		vector<ll> vals(m);
		for (int i = 0; i < m; i++) cin >> vals[i];
		
		sort(vals.begin(), vals.end());
		
		int cap = bs(0, m-1, vals);
		while (valid(cap + 1, vals))
			cap++;
		
		printf("%d\n", cap);
	}
	return 0;
}
