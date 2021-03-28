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

ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, k; cin >> n >> k;
	vector<vector<ll>> ans;
	ll max = 0;
	ll cur = 1;
	for (int i = 0; i < n; i++) {
		vector<ll> set;
		while (cur % 2 != 1)
			cur++;
		ll cur_gcd = cur * (cur+1) * (cur+2);
		set.pb(cur * k);
		set.pb((cur + 1) * k);
		set.pb((cur + 2) * k);
		cur += 3;
		while (gcd(cur_gcd, cur) != 1)
			cur++;
		set.pb(cur * k);
		max = cur * k;
		cur++;
		ans.pb(set);
	}
	cout << max << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++)
			printf("%lld ", ans[i][j]);
		printf("\n");
	}
	return 0;
}
