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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<ll> vals(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> vals[i];
		vals[i] += vals[i-1];
	}
	
	int cnt = 0;
	set<ll> cur;
	for (int i = 0; i <= n; i++) {
		ll val = vals[i];
		bool contains = cur.find(val) != cur.end();
		if (contains) {
			cnt++;
			cur.clear();
			if (i != 0) {
				cur.insert(vals[i-1]);
			}
		}
		cur.insert(val);
	}
	printf("%d\n", cnt);
	return 0;
}
