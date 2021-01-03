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
		int n; cin >> n;
		vector<int> vals(2*n+1);
		for (int i = 0; i < n; i++) {
			int a; cin >> a; vals[a]++;
		}
		int cnt = 0;
		int prev = 0;
		for (int i = 0; i <= 2*n; i++) {
			if (prev > 0) {
				cnt++;
			} else if (vals[i] > 0) {
				vals[i]--;
				cnt++;
			}
			prev = vals[i];
		}
		if (prev > 0) cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
