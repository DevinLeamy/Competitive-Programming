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
		vector<int> vals(n);
		int ones = 0;
		int twos = 0;
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
			if (vals[i] == 2) {
				twos++;
			} else {
				ones++;
			}
		}
		if (ones % 2 != 0) {
			printf("NO\n");
		} else if (twos % 2 == 0 && ones % 2 == 0) {
			printf("YES\n");
		} else if (twos % 2 == 1 && ones >= 2) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
