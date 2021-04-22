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
#define view2(a, b) cout << "DEBUG: " << a << " " << b << endl;
using namespace std;
char _;

bool solve() {
	ll u, v; cin >> u >> v;
	if (u > v)
		return false;
	vector<int> u_bits(35), v_bits(35);
	int u_cnt = 0, v_cnt = 0;
	int u_last = 0, v_last = 0;
	for (int i = 0; i < 35; i++) {
		if (u & 1) {
			u_bits[i] = 1;
			u_last = i;
			u_cnt++;
		}
		if (v & 1) {
			v_bits[i] = 1;
			v_last = i;
			v_cnt++;
		}
			
		u /= 2ll;
		v /= 2ll;
	}
	if (v_last < u_last || v_cnt > u_cnt)
		return false;
	
	int idx = 0;
	for (int i = 0; i < 35 && v_cnt > 0; i++) {
		if (u_bits[i] == 0)
			continue;
		// Remove until empty or 1
		while (!v_bits.empty() && v_bits.front() == 0) {
			v_bits.erase(v_bits.begin());
			idx++;
		}
		
		if (v_bits.empty() || idx < i)
			return false;
		
		// Remove 1
		v_bits.erase(v_bits.begin());
		idx++;
		v_cnt--;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int q; cin >> q;
	loop(q) {
		if (solve()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
