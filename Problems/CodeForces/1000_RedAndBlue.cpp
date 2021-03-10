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

int solve() {
	int n; cin >> n;
	vector<int> red(1+n);
	for (int i = 1; i <= n; i++) {
		cin >> red[i];
		red[i] += red[i - 1];
	}
		
	int m; cin >> m;
	vector<int> blue(1+m);
	for (int i = 1; i <= m; i++) {
		cin >> blue[i];
		blue[i] += blue[i - 1];
	}
	
	int max_red = 0, max_blue = 0;
	for (int i = 0; i <= n; i++)
		max_red = max(max_red, red[i]);
	for (int i = 0; i <= m; i++)
		max_blue = max(max_blue, blue[i]);
	
	return max_red + max_blue;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		printf("%d\n", solve());
	}
	return 0;
}
