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
		int n, a, last = 0, count = 0, c = 0, b = 0; cin >> n;
		vector<int> vals;
		int lp = 0, rp = n-1;
		for (int i = 0; i < n; i++) { cin >> a; vals.pb(a); }
		bool al = true;
		while (lp <= rp) {
			int sum = 0;
			while (sum <= last && lp <= rp) {
				if (al) {
					sum += vals[lp];
					c += vals[lp];
					lp++;
				} else {
					sum += vals[rp];
					b += vals[rp];
					rp--;
				}
			}
			last = sum;
			count++;
			al = !al;
		}
		cout << count << " " << c << " " << b << endl;
	}
	return 0;
}
