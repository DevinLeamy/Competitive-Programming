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
		int n; cin >> n;
		//2*3, 2*5, 2*7
		if (n > 2*3 + 2*5 + 2*7) {
			cout << "YES" << endl;
			int total = 2*3 + 2*5 + 2*7;
			if (n - total == 14 || n-total == 10 || n-total == 6) {
				total += 1;
				cout << 2*3 << " " << 2*5 << " " << 3 * 5 << " " << n - total << endl;
			} else {
				cout << 2*3 << " " << 2*5 << " " << 2 * 7 << " " << n - total << endl;
			}
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
