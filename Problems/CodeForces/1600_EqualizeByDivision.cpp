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


vector<vector<int>> cost(200001);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k, a; cin >> n >> k;
	vector<int> vals;
	for (int i = 0; i < n; i++) {
		cin >> a; vals.pb(a);
	}
	sort(vals.begin(), vals.end());
	for (int val : vals) {
		cost[val].pb(0);
		int count = 1;
		while (val != 0) {
			val >>= 1;
			cost[val].pb(count);
			count++;
		}
	}
	int min = INF;
	for (int i = 0; i <= 200000; i++) {
		int sum = 0;
		if (cost[i].size() < k) continue;
		for (int j = 0; j < k; j++) {
			sum += cost[i][j];
		}
		min = std::min(min, sum);
	}
	cout << min;
	return 0;
}
