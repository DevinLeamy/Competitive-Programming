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

ll mod = 1000000007ll;
int MAXN = 2000005;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	vector<PL> lvl(MAXN, PL());
	lvl[1].first = 1;
	for (int i = 2; i < MAXN; i++) {
		lvl[i].first = (lvl[i - 1].first + 2 * lvl[i - 1].second) % mod;
		lvl[i].second = lvl[i - 1].first;
		if (i % 3 == 1)
			lvl[i].first = (lvl[i].first + 1) % mod;
	}
	loop(t) {
		int n; cin >> n;
		ll total = (lvl[n - 1].second * 4ll) % mod;
		cout << total << endl;
	}
	return 0;
}
