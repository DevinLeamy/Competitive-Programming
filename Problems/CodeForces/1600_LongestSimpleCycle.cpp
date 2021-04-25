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

int MAXN = 100005;
vector<ll> cnts(MAXN);
vector<PI> connect(MAXN);
ll solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cnts[i];
	for (int i = 0; i < n; i++)
		cin >> connect[i].first;
	for (int i = 0; i < n; i++)
		cin >> connect[i].second;
	for (int i = 0; i < n; i++) {
		PI temp = connect[i];
		connect[i].first = max(temp.first, temp.second);
		connect[i].second = min(temp.first, temp.second);
	}
	ll ans = 0;
	ll prev = 0;
	for (int i = 1; i < n; i++) {
		ll diff = connect[i].first - connect[i].second;
		ll new_prev = 2ll;
		if (diff != 0) {
			if (i != 1)
				new_prev = max(diff + 2ll, prev + 2ll + ((cnts[i - 1] - 1ll) - (connect[i].first - connect[i].second)));
			else
				new_prev = diff + 2ll;
		}
			
		ans = max(ans, new_prev + (cnts[i] - 1ll));
		prev = new_prev;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		printf("%lld\n", solve());
	}
	return 0;
}
