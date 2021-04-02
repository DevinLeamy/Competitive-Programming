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
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		ll n; cin >> n;
//		ll digits = 0;
//		for (int i = 0; i < (int) n.length(); i++)
//			digits += n[i] - '0';
		ll ans = n;
		while (1) {
			ll digits = 0;
			string val = to_string(ans);
			for (int i = 0; i < (int) val.length(); i++)
				digits += val[i] - '0';
			if (gcd(digits, ans) != 1)
				break;
			ans++;
		}
		cout << ans << endl;
		
	}
	return 0;
}
