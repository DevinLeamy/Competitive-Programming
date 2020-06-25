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

int minDigit(ll n) {
	string num = to_string(n);
	int min = 9;
	for (int i = 0; i < num.length(); i++) {
		min = std::min(min, num[i] - '0');
	}
	return min;
}
int maxDigit(ll n) {
	string num = to_string(n);
	int max = 0;
	for (int i = 0; i < num.length(); i++) {
		max = std::max(max, num[i] - '0');
	}
	return max;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		ll a, k, cur = 1; cin >> a >> k;
		ll ans = a;
		while (cur != k) {
			int inc = maxDigit(ans) * minDigit(ans);
			if (inc == 0) { break; }
			ans += inc;
			cur++;
		}
		cout << ans << endl;
	}
	return 0;
}
