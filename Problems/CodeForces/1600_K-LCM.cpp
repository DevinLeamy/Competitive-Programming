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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		ll n; int k; cin >> n >> k;
		n -= (k - 3);
		for (int i = 0; i < (k - 3); i++)
			printf("1 ");
			
		if (n % 2 == 1)
			printf("%lld %lld %lld\n", n/2, n/2, 1ll);
		else {
			if (n % 4 == 0)
				printf("%lld %lld %lld\n", n/2, n/4, n/4);
			else
				printf("%lld %lld %lld\n", (n - 1)/2, (n - 1)/2, 2ll);
		}
	}
	return 0;
}
