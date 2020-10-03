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
	int t; cin >> t;
	loop(t) {
		int n, m; cin >> n >> m;
		bool works = false;
		for (int i = 0; i < n; i++) {
			PI top, bottom;
			cin >> top.first >> top.second;
			cin >> bottom.first >> bottom.second;
			if (top.second == bottom.first) { works = true; }
		}
		cout << ((works && m % 2 == 0)? "YES":"NO") << endl;
	}
	return 0;
}
