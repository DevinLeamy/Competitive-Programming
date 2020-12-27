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
	ll u, v; cin >> u >> v;
	
	if (u == 0 && v == 0) { cout << 0 << "\n"; return 0; }
	else if (u == v) { cout << 1 << "\n" << u << "\n"; return 0; }
	else if (u > v || (u % 2 - v % 2 != 0)) { cout << -1 << "\n"; return 0; }
	ll d = v - u;
	
	vector<bool> u_on(60), d_on(60);
	ll temp_u = u, temp_d = d;
	for (int i = 59; i >= 0; i--) {
		ll p = (ll) pow(2, i);
		d_on[i] = temp_d >= p; temp_d %= p;
		u_on[i] = temp_u >= p; temp_u %= p;
	}
	ll nxt = 0, snd = 0, first = u;
	bool need_three = false;
	
	for (int i = 59; i >= 0; i--) {
		if (d_on[i]) {
			if (i != 0 && u_on[i-1]) need_three = true;
			else {
				first += pow(2, i-1);
				snd += pow(2, i-1);
			}
			nxt += pow(2, i-1);
		}
	}
	if (need_three) {
		cout << 3 << "\n";
		cout << u << " " << nxt << " " << nxt << "\n";
	} else {
		cout << 2 << "\n";
		cout << first << " " << snd << "\n";
	}
	return 0;
}
