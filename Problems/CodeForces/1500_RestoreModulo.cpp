#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
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
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;
char _;

vector<ll> solve() { // m
	int n; cin >> n;
	vector<ll> vals(n);
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	if (n == 1)
		return {0};
	bool equal = true;
	for (int i = 0; i < n - 1; i++) {
		if (vals[i+1] - vals[i] != vals[1] - vals[0])
			equal = false;
	}
	if (equal) {
		return {0};
	}
	
	ll c = -1;
	for (int i = 0; i < n - 1; i++) {
		if (vals[i + 1] >= vals[i]) {
			c = vals[i + 1] - vals[i];
			break;
		}
	}
	ll cur_m = 0;
	if (c == -1) {
		cur_m = vals[0] + 5435;
		c = vals[1] - vals[0] + cur_m;
	}
	for (int i = 0; i < n - 1; i++) {
		ll diff = vals[i + 1] - vals[i];
		if (diff >= 0) {
			if (diff != c) {
				return {};
			}
		} else {
			ll mod = vals[i] + c - vals[i + 1];
			if (cur_m == 0)
				cur_m = mod;
			else if (cur_m != 0 && cur_m != mod)
				return {};
		}
	}
	if (cur_m == 0)
		return {0};
	if (vals[0] % cur_m != vals[0])
		return {};
	for (int i = 0; i < n - 1; i++) {
		if ((vals[i] + c) % cur_m != vals[i + 1])
			return {};
	}
	return {cur_m, c};
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		vector<ll> res = solve();
		if (res.empty())
			printf("-1\n");
		else {
			if (res.size() == 1)
				printf("0\n");
			else
				printf("%lld %lld\n", res[0], res[1]);
		}
			
	}
	return 0;
}
