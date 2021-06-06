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
#define view2(a, b) cout << "DEBUG: " << a << " " << b << endl;
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<int> vals(n);
	vector<int> vacant;
	vector<int> occ;
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
		if (vals[i] == 1)
			occ.pb(i);
		else
			vacant.pb(i);
	}
	ll ans = 0;
	vector<int> cur((int) occ.size());
	for (int i = 0; i < occ.size(); i++) {
		cur[i] = i;
		ans += abs(occ[i] - vacant[i]);
	}
	
	for (int i = 0; i < (int) occ.size(); i++) {
		while (1) {
			ll new_score = 0;
			ll old_score = 0;
			for (int j = 0; j < i; j++) {
				new_score += abs(occ[j] - vacant[cur[j]]);
				old_score += abs(occ[j] - vacant[cur[j]]);
			}
			for (int j = i; j < (int) occ.size(); j++) {
				if (cur[j] + 1 >= (int) vacant.size()) {
					new_score = LINF;
					break;
				}
				old_score += abs(occ[j] - vacant[cur[j]]);
				new_score += abs(occ[j] - vacant[cur[j] + 1]);
				if (old_score <= new_score)
					break;
			}
			if (old_score > new_score) {
				for (int j = i; j < (int) occ.size(); j++)
					cur[j]++;
				ans = new_score;
			} else {
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
