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

int d[10000001];
int ans[10000001];
int n = 10000001ll;
ll solve() {
	ll c; cin >> c;
	return (ans[c] == 0)?  -1 : ans[c];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (d[j] > n)
				continue;
			d[j] += i;
		}

		if (d[i] <= n) {
			if (ans[d[i]] == 0)
				ans[d[i]] = i;
			ans[d[i]] = min(ans[d[i]], i);
		}
	}
	loop(t) {
		cout << solve() << endl;
	}
	return 0;
}
