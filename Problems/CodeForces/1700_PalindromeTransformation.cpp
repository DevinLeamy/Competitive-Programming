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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, p; cin >> n >> p;
	p--;
	string s; cin >> s;
	int cost = 0;
	int l = p;
	int r = p;
	for (int i = 0; i < n/2; i++) {
		int cur = s[i] - 'a', right = s[n - 1 - i] - 'a';
		if (cur == right)
			continue;
		if (cur > right)
			swap(cur, right);
		int mvs = min(right - cur, cur + (26 - right));
		cost += mvs;
		if (p < n/2) {
			l = min(l, i);
			r = max(r, i);
		} else {
			l = min(l, n - 1 - i);
			r = max(r, n - 1 - i);
		}
	}
	cost += min((p - l) * 2 + (r - p), (r - p) * 2 + (p - l));
	
	
	cout << cost << endl;
	return 0;
}
