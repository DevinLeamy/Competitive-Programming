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
		int n; cin >> n;
		vector<pair<ll, int>> vals(n);
		for (int i = 0; i < n; i++) {
			cin >> vals[i].first;
			vals[i].second = i;
		}
		sort(vals.begin(), vals.end());
		vector<ll> presum(n + 1);
		for (int i = 0; i < n; i++) {
			presum[i + 1] = presum[i] + vals[i].first;
		}
		vector<int> can_win;
		can_win.pb(vals[n - 1].second);
		for (int i = n - 2; i >= 0; i--) {
			if (presum[i + 1] >= vals[i + 1].first)
				can_win.pb(vals[i].second);
			else
				break;
		}
		sort(can_win.begin(), can_win.end());
		cout << can_win.size() << endl;
		for (int val : can_win)
			cout << val + 1 << " ";
		cout << "\n";
	}
	return 0;
}
