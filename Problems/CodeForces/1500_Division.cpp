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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		ll p, q; cin >> p >> q;
		ll x = 0;
		for(ll i = 1; i * i <= q; i++){
			if (q % i == 0){
				if (i != 1){
					ll tmp = p;
					while (tmp % q == 0) tmp /= i;
					x = max(x, tmp);
				}
				ll tmp = p;
				while(tmp % q == 0) tmp /= q / i;
				x = max(x, tmp);
			}
		}
		printf("%lld\n", x);
	}
	return 0;
}
