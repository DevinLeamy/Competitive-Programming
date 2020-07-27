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
		ll n, m, a, b; cin >> n >> m;
		vector<pair<PL, PI>> vals;
		vector<bool> added(m);
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			vals.pb({{a, b}, {0, i}});
			vals.pb({{b, a}, {1, i}});
		}
		sort(vals.rbegin(), vals.rend());
		ll bestV = 0;
		ll sum = 0;
		ll count = 0;
		for (int i = 0; i < vals.size(); i++) {
			if (vals[i].second.first == 1) {
				ll newV = (n-count) * vals[i].first.first + sum;
				if (!added[vals[i].second.second]) {
					newV += vals[i].first.second;
					newV -= vals[i].first.first;
				}
				bestV = max(newV, bestV);
				
			} else {
				added[vals[i].second.second] = true;
				sum += vals[i].first.first;
				count++;
				if (count == n) {
					bestV = max(bestV, sum);
					break;
				}
			}
		}
		cout << bestV << endl;
	}
	return 0;
}
