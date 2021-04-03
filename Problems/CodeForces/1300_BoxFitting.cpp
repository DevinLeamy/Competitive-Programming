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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n; ll w; cin >> n >> w;
		vector<ll> vals(n);
		vector<int> cntr(64);
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
			cntr[log2(vals[i])]++;
		}
		ll cnt = 0;
		int taken = 0;
		while (taken != n) {
			ll sum = w;
			cnt++;
			for (int i = 32; i >= 0; i--) {
				int take = min((ll) cntr[i], (ll) sum / (ll) pow(2, i));
				sum -= (ll) take * pow(2, i);
				cntr[i] -= take;
				taken += take;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
