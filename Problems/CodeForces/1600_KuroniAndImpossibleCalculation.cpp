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
	int n, m; cin >> n >> m;
	vector<ll> vals(n);
	for (int i = 0; i < n; i++) cin >> vals[i];
	ll prod = 1;
	if (n > m) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			prod = (prod * abs(vals[i] - vals[j])) % m;
		}
	}
	printf("%lld\n", prod);
	return 0;
}
