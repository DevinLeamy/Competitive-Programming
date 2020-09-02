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

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int lcm(int a, int b) {
	return (a * b)/gcd(a, b);
}

ll query(ll l, vector<int>& preSum, int lcm) {
	ll cnt = l / lcm;
	int rem = l % lcm;
	return preSum[lcm] * 1ll * cnt + preSum[rem];
}

ll query(ll l, ll r, vector<int>& preSum, int lcm) {
	return query(r, preSum, lcm) - query(l - 1, preSum, lcm);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int a, b, q; cin >> a >> b >> q;
		int lcm = ::lcm(a, b);
		vector<int> preSum(lcm + 1);
		int temp = min(a, b);
		a = max(a, b);
		b = temp;
		for (int i = 0; i <= lcm; i++) {
			bool equal = ((i % a)%b) == ((i % b)%a);
			if (!equal) preSum[i]++;
			if (i != 0) preSum[i] += preSum[i-1];
		}
		for (int i = 0; i < q; i++) {
			ll l, r; cin >> l >> r;
			ll ans = query(l, r, preSum, lcm);
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}
