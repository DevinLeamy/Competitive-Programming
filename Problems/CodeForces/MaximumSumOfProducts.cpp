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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	ll ans = 0;
	vector<ll> base(n);
	ll total = 0;
	for (int i = 0; i < n; i++) {
		base[i] = a[i] * b[i];
		total += a[i] * b[i];
	}
	for (int i = 0; i < n; i++) {
		// Let i be the center or
		
		// Let center be i
		ll cur = total;
		int lp = i - 1, rp = i + 1;
		while (lp >= 0 && rp < n) {
			ans = max(ans, cur);
			cur -= base[lp] + base[rp];
			cur += b[lp] * a[rp] + b[rp] * a[lp];
			lp--; rp++;
			
		}
		ans = max(ans, cur);
		
		if (i == n - 1)
			break;
		// Let center be i and i + 1
		cur = total;
		cur -= base[i] + base[i + 1];
		cur += a[i + 1] * b[i] + a[i] * b[i + 1];
		lp = i - 1; rp = i + 2;
		while (lp >= 0 && rp < n) {
			ans = max(ans, cur);
			cur -= base[lp] + base[rp];
			cur += b[lp] * a[rp] + b[rp] * a[lp];
			lp--; rp++;
		}
		ans = max(ans, cur);
	}
	printf("%lld\n", ans);
	return 0;
}
