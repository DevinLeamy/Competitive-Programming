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
	int t; cin >> t;
	loop(t) {
		ll r, b, k; cin >> r >> b >> k;
		ll g = gcd(r, b);
		if (r < b) swap(r, b);
		r /= g;
		b /= g;
		
		ll cnt = ceil((double)(r - 1) / b) + 1;
		if (k >= cnt) printf("OBEY\n");
		else printf("REBEL\n");
	}
	return 0;
}
