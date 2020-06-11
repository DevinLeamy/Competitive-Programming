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
 
ll func(ll a, ll b, ll c) {
	return (a-b) * (a-b) + (b-c) * (b-c) + (c-a) * (c-a);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int r, g, b, rI = 0, gI = 0, bI = 0; cin >> r >> g >> b;
		ll n;
		vector<ll> red;
		vector<ll> green;
		vector<ll> blue;
		red.clear(); green.clear(); blue.clear();
		for (int i = 0; i < r; i++) { cin >> n; red.pb(n); }
		for (int i = 0; i < g; i++) { cin >> n; green.pb(n); }
		for (int i = 0; i < b; i++) { cin >> n; blue.pb(n); }
		sort(red.begin(), red.end());
		sort(green.begin(), green.end());
		sort(blue.begin(), blue.end());
		ll best = func(red[0], green[0], blue[0]);
		while(rI != r-1 || gI != g-1 || bI != b-1) {
			ll rV = red[rI]; ll gV = green[gI]; ll bV = blue[bI];
			vector<vector<int>> can;
			if (((rV <= ((gI == g-1)? LINF : gV) || rV <= ((bI == b-1)? LINF : bV)) && rI != r-1) || (bI == b-1 && gI == g-1)) {
				can.pb({1, 0, 0});
			}
			if (((bV <= ((rI == r-1)? LINF : rV) || bV <= ((gI == g-1)? LINF : gV)) && bI != b-1) || (rI == r-1 && gI == g-1)) {
				can.pb({0, 0, 1});
			}
			if (((gV <= ((rI == r-1)? LINF : rV) || gV <= ((bI == b-1)? LINF : bV)) && gI != g-1) || (rI == r-1 && bI == b-1)){
				can.pb({0, 1, 0});
			}
			pair<vector<int>, ll> opt = {{-1, -1, -1}, LINF};
			for (vector<int> val : can) {
				if (opt.second > func(red[rI+val[0]], green[gI+val[1]], blue[bI+val[2]])) {
					opt.first = val;
					opt.second = func(red[rI+val[0]], green[gI+val[1]], blue[bI+val[2]]);
				}
			}
			rI += opt.first[0]; gI += opt.first[1]; bI += opt.first[2];
			best = min(best, func(red[rI], green[gI], blue[bI]));
		}
		cout << best << endl;
	}
	return 0;
}
