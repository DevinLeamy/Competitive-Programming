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

bool solve() {
	int n; ll k; cin >> n >> k;
	vector<ll> heights(n);
	for (int i = 0; i < n; i++)
		cin >> heights[i];
	
	vector<PL> ranges; ranges.pb({heights[0], heights[0] + k}); // low, high
	for (int i = 1; i < n; i++) {
		PL last = ranges[i - 1];
		ll low = max(heights[i], last.first - (k - 1));
		if (last.second <= heights[i])
			return false;
		
		ll high = min(heights[i] + (k - 1) + k, last.second + (k - 1));
		if (low - heights[i] > (k - 1))
			return false;

		ranges.pb({low, high});
	}
	if (ranges.back().first != heights.back())
		return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		if (solve())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
