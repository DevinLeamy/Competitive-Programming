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
		int n; cin >> n;
		vector<PI> ans;
		int div = n;
		int cur = n - 1;
		int idx = n - 2;
		while (div != 1) {
			if (ceil((double) div / (double) cur) >= cur || cur == 2) {
				ans.pb({n, cur});
				div = (int) ceil((double)div / (double)cur);
				continue;
			}
			ans.pb({cur, n});
			cur--;
		}
		cout << (int) ans.size() << endl;
		for  (PI move : ans)
			cout << move.first << " " << move.second << endl;
		cout << endl;
	}
	return 0;
}
