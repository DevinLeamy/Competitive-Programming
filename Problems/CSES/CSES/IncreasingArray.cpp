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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<ll> vals(n);
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	
	ll ans = 0;
	ll cur = vals[0];
	for (int i = 1; i < n; i++) {
		ans += max(0ll, cur - vals[i]);
		cur = max(cur, vals[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
