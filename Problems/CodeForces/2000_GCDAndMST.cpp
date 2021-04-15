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
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int find_set(int v, vector<int> &par) {
    if (v == par[v])
        return v;
    return par[v] = find_set(par[v], par);
}

void union_sets(int a, int b, vector<int> &par) {
    a = find_set(a, par);
    b = find_set(b, par);
    if (a != b)
        par[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n; ll p;
		cin >> n >> p;
		vector<ll> vals(n);
		vector<PL> less;
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
			if (vals[i] < p) {
				less.pb(make_pair(vals[i], i));
			}
		}
		sort(less.begin(), less.end());
		ll ans = 0;
		vector<int> par(n);
		vector<bool> in_set(n);
		for (int i = 0; i < n; i++)
			par[i] = i;
		
		int edges = 0;
		for (PL lesser : less) {
			if (edges == n - 1)
				break;
			ll val = lesser.first;
			int idx = (int) lesser.second;
			int lp = idx, rp = idx;
			ll cur_g = val;
			ll cur_m = val;
			while (lp - 1 != -1 && cur_m == gcd(vals[lp - 1], cur_g)) {
				if (find_set(lp - 1, par) == find_set(idx, par))
					break;
				lp--;
				union_sets(lp, idx, par);
				if (in_set[lp])
					break;
			}
				
			while (rp + 1 != n && cur_m == gcd(vals[rp + 1], cur_g)) {
				if (find_set(rp + 1, par) == find_set(idx, par))
					break;
				rp++;
				union_sets(rp, idx, par);
				if (in_set[rp])
					break;
			}
				
			if (lp == rp && lp == idx)
				continue;
			for (int i = lp; i <= rp; i++)
				in_set[i] = true;
			ans += (rp - lp) * cur_m;
			edges += (rp - lp);
		}
		ans += p * (n - 1 - edges);
		cout << ans << endl;
	}
	return 0;
}
