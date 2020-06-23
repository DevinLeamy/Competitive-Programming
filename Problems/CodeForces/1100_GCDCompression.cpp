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
		int n, a; cin >> n;
		vector<int> even;
		vector<int> odd;
		for (int i = 0; i < 2*n; i++) {
			cin >> a;
			if (a % 2 == 0) { even.pb(i+1); }
			else { odd.pb(1+i); }
		}
		int curO = 0;
		int curE = 0;
		for (int i = 0; i < 2*n - 2; i += 2) {
			if (curO + 2 < odd.size()) {
				cout << odd[curO] << " " << odd[curO + 1] << endl;
				curO += 2;
			} else {
				cout << even[curE] << " " << even[curE + 1] << endl;
				curE += 2;
			}
		}
	}
	return 0;
}
