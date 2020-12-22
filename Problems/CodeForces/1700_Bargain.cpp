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

ll mod = 1000000007ll;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	string n; cin >> n;
	ll ans = 0;
	int len = (int) n.length();
	vector<ll> presum;
	vector<ll> pows(len+1);
	pows[0] = 1;
	for (int i = 0; i < len; i++) {
		pows[i+1] = (pows[i] * 10) % mod;
	}
	presum.pb(0);
	for (int i = 1; i <= len; i++) {
		presum.pb(i * pows[i-1]);
		if (i != 0) presum[i] += presum[i-1];
		presum[i] %= mod;
	}
	for (int i = 0; i < len; i++) {
		int num = n[i] - '0';
		int rem = len - i - 1;
		double pos = i + 1;
		ll power = (int) n.length() - i - 1;
		ll options = (pos * (pos - 1) * 0.5);
		ans += (((options * pows[power]) % mod) * num) % mod;
		ans += (presum[rem] * num) % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
