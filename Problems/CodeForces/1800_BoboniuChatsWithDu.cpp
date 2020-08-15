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
	int n, d; ll m; cin >> n >> d >> m;
	vector<ll> larger;
	vector<ll> smaller;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		if (a > m) larger.pb(a);
		else smaller.pb(a);
	}
	ll max = 0;
	ll cur = 0;
	sort(larger.rbegin(), larger.rend());
	sort(smaller.rbegin(), smaller.rend());
	for (int i = 0; i <= min((int)larger.size(), (n-1)/(d + 1) + 1); i++) {
		ll sum = 0;
		ll rem = n - (i - 1)*(d+1) - 1;
		if (i == 0) rem = n;
		else cur += larger[i-1];
		for (int j = 0; j < min((ll)smaller.size(), rem); j++) {
			sum += smaller[j];
		}
		max = std::max(max, cur + sum);
	}
	cout << max << endl;
	return 0;
}
