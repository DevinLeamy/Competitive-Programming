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

ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		vector<ll> vals(n);
		for (int i = 0; i < n; i++)
			cin >> vals[i];
		set<int> ps;
		vector<int> next_v(n);
		for (int i = 0; i < n; i++) {
			next_v[i] = (i + 1) % n;
		}
		for (int i = 0; i < n; i++) {
			int next = (i + 1) % n;
			ll gd = gcd(vals[i], vals[next]);
			if (gd == 1) {
				ps.insert(i); 
			}
		}
		vector<int> ans;
		vector<bool> rem(n);
		int cur = 0;
		while (!ps.empty()) {
			int idx = *ps.lower_bound(cur);
			if (ps.lower_bound(cur) == ps.end()) {
				idx = *ps.begin();
			}
			if (rem[idx] || rem[next_v[idx]]) {
				ps.erase(idx);
				continue;
			}
			cur = next_v[idx];
			rem[next_v[idx]] = true;
			ans.pb(next_v[idx] + 1);
			next_v[idx] = next_v[next_v[idx]];
			ps.erase(idx);
			
			int next = next_v[idx];
			if (gcd(vals[idx], vals[next]) == 1)
				ps.insert(idx);
		}
		cout << ans.size() << " ";
		for (int val : ans)
			cout << val << " ";
		cout << endl;
	}
	return 0;
}
