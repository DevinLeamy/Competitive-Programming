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
	int t; cin >> t;
	loop(t) {
		ll n, k, z; cin >> n >> k >> z;
		vector<int> vals(n);
		int a;
		vector<int> preSum;
		preSum.pb(0);
		for (int i = 0; i < n; i++) {
			cin >> a; vals[i] = a;
			preSum.pb(preSum[i] + a);
		}
		ll best = 0;
		ll currentSum = 0;
		for (int i = 0; i <= k; i++) {
			currentSum += vals[i];
			ll score = currentSum;
			ll movesRem = k;
			if (i != 0) {
				movesRem -= i;
				ll backWards = min(z, movesRem / 2 + movesRem%2);
				ll forwards = min((movesRem - backWards), backWards);
				score += backWards * vals[i-1] + forwards * vals[i];
				movesRem -= backWards + forwards;
			}
			score += preSum[i + movesRem + 1] - preSum[i + 1];
			best = max(best, score);
		}
		cout << best << endl;
	}
	return 0;
}
