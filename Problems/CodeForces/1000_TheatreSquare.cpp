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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, a; cin >> n >> m >> a;
	if (n <= a && m <= a) {
		cout << 1;
		return 0;
	}
	m -= a;
	ll across = (n/a + ((n%a==0)? 0 : 1));
	ll up = (m/a + ((m%a==0)? 0 : 1));
	ll ans = up * across + across;
	cout << ans << endl;
	return 0;
}
