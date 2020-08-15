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
	int n, m, sx, sy; cin >> n >> m >> sx >> sy;
	cout << sx << " " << sy << endl;
	int curx = n;
	for (int i = 1; i <= n; i++) {
		if (i == sx) continue;
		cout << i << " " << sy << endl;
		curx = i;
	}
	for (int i = 1; i <= m; i++) {
		if (i == sy) continue;
		cout << curx << " " << i << endl;
		int temp = 0;
		for (int j = n; j >= 1; j--) {
			if (j == curx) continue;
			cout << j << " " << i << endl;
			temp = j;
		}
		curx = temp;
	}
	return 0;
}
