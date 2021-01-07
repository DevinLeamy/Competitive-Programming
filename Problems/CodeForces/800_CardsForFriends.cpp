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
		ll w, h, n; cin >> w >> h >> n;
		ll cnt1 = 0, cnt2 = 0;
		while (w % 2 == 0) {
			w /= 2;
			cnt1++;
		}
		
		while (h % 2 == 0) {
			h /= 2;
			cnt2++;
		}
		
		if (pow(2, cnt1) * pow(2, cnt2) >= n) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
