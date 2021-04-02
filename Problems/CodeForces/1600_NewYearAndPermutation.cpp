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

ll mod;
ll facts[250001];

ll mult(ll a, ll b) {
	return (a * b) % mod;
}

ll add(ll a, ll b) {
	return (a + b) % mod;
}

ll fact(ll n) {
	if (n == 0 || n == 1)
		return 1ll;
	if (facts[n] != 0)
		return facts[n];
	facts[n] = mult(n, fact(n - 1));
	return facts[n];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n >> mod;
	ll ans = 0;
	for (int i = 0; i <= n; i++)
		facts[i] = 0;
	for (int d = 0; d < n; ++d) {
		ll cnt = mult(n - d, fact(d + 1)); // Number of pairs (r - l) = d and permutations of values within their bounds
		cnt = mult(cnt, fact(n - (d + 1))); // Permutations of numbers not within bounds
		cnt = mult(cnt, n - d); // Number of starting positions
		ans = add(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
