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

bool solve() {
	int n; cin >> n;
	vector<ll> vals(2*n);
	for (int i = 0; i < 2*n; i++)
		cin >> vals[i];
	sort(vals.rbegin(), vals.rend());
	ll cnt = 1;
	ll last = vals[0];
	vector<ll> nums;
	nums.pb(last);
	for (int i = 1; i < 2*n; i++) {
		if (vals[i] == last)
			cnt++;
		else {
			last = vals[i];
			if (cnt != 2)
				return false;
			cnt = 1;
			nums.pb(last);
		}
	}
	if (cnt != 2)
		return false;
	
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll di = nums[i];
		ll rem_lar = di - sum;
		if (rem_lar <= 0 || rem_lar % (2 * (n - i)) != 0)
			return false;
		ll x = rem_lar / (2 * (n - i));
		sum += 2*x;
	}
	
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		if (solve())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
