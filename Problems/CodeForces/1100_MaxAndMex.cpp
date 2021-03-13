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

ll solve() {
	ll n, k; cin >> n >> k;
	vector<ll> vals(n);
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	
	if (k == 0)
		return n;
	
	ll added = 0;
	sort(vals.begin(), vals.end());
	
	ll mex = -1;
	ll max = vals.back();
	
	for (int i = 0; i < n; i++) {
		if (i != vals[i]) {
			mex = i;
			break;
		}
	}
	if (mex == -1)
		return n + k;
	
	ll val = (max + mex) / 2 + (max + mex) % 2;
	if (!binary_search(vals.begin(), vals.end(), val))
		added++;
	return added + n;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		printf("%lld\n", solve());
	}
	return 0;
}
