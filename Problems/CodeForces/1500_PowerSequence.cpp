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
	int n; cin >> n;
	vector<ll> vals(n);
	for (int i = 0; i < n; i++) cin >> vals[i];
	sort(vals.begin(), vals.end());
	ll minCost = LINF;
	for (int i = 1; i < 1000000; i++) {
		ll cost = 0;
		ll max = log(LINF)/log(i);
		if (max < n && i != 1) break;
		for (int j = 0; j < n; j++) {
			cost += abs(pow(i, j) - vals[j]);
			if (cost < 0) break;
		}
		if (cost < 0) break;
		minCost = min(minCost, cost);
	}
	cout << minCost << endl;
	return 0;
}
