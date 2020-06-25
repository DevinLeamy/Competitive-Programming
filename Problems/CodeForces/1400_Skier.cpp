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
	int t; cin >> t;
	loop(t) {
		string s; cin >> s;
		set<pair<PI, PI>> path;
		PI cur = { 0, 0 };
		ll ans = 0;
		for (int i = 0; i < s.length(); i++) {
			PI pre = cur;
			if (s[i] == 'N') { cur.first++; }
			if (s[i] == 'S') { cur.first--; }
			if (s[i] == 'E') { cur.second++; }
			if (s[i] == 'W') { cur.second--; }
			if (path.count({pre, cur}) || path.count({cur, pre})) { ans++; }
			else { path.insert({pre, cur}); ans += 5; }
		}
		cout << ans << endl;
	}
	return 0;
}
