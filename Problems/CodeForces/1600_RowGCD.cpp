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

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, m; cin >> n >> m;
	vector<ll> a(n), b(m);
	
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	
	ll base = (n > 1)? a[1] - a[0] : 0;
	for (int i = 2; i < n; i++)
		base = gcd(base, a[i] - a[0]);
	
	for (int i = 0; i < m; i++)
		cout << abs(gcd(base, a[0] + b[i])) << " ";
	return 0;
}
