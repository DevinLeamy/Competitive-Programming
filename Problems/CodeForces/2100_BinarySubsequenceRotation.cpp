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
	int n, cur0 = 0, cur1 = 0, count = 0, max = 0; cin >> n;
	string s, k; cin >> s >> k;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') { count--; }
		if (k[i] == '1') { count++; }
		if (s[i] == '1' && k[i] == '0') { cur0++; cur1--; }
		else if (s[i] == '0' && k[i] == '1') { cur0--; cur1++; }
		max = std::max(max, cur0);
		max = std::max(max, cur1);
		if (cur0 < 0) { cur0 = 0; }
		if (cur1 < 0) { cur1 = 0; }
	}
	if (count == 0) { cout << max; }
	else { cout << -1; }
	return 0;
}
