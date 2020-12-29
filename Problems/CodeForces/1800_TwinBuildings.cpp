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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(1);
	int n; cin >> n;
	vector<pair<long double, long double>> vals(n);
	for (int i = 0; i < n; i++) {
		long double l, w; cin >> l >> w;
		if (l < w) swap(l, w);
		vals[i] = { l, w };
	}
	
	sort(vals.begin(), vals.end());
	vector<long double> wths(n+1);
	wths[n] = 0;
	for (int i = n-1; i >= 0; i--)
		wths[i] = max(vals[i].second, wths[i+1]);
	
	long double max_1 = 0;
	long double max_2 = 0;
	for (int i = 0; i < n; i++) {
		long double len = vals[i].first;
		long double wth = vals[i].second;
		max_1 = max(max_1, (wth * len) / (long double) 2.0);
		max_2 = max(max_2, len * min(wth, wths[i+1]));
	}
	cout << fixed << max(max_1, max_2);
	return 0;
}
