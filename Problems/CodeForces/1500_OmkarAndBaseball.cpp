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
		vector<int> vals(n);
		int lpt = 0;
		int rpt = n-1;
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
		}
		for (int i = 0; i < n; i++) {
			if (vals[i] == i+1) {
				lpt++;
			} else {
				break;
			}
		}
		for (int i = n-1; i >= 0; i--) {
			if (vals[i] == i+1) {
				rpt--;
			} else {
				break;
			}
		}
		if (lpt == n) {
			cout << 0 << endl;
			continue;
		}
		bool flag = false;
		for (int i = lpt; i <= rpt; i++) {
			if (vals[i] == i+1) {
				flag = true;
			}
		}
		if (flag) {
			cout << 2 << endl;
		} else {
			cout << 1 << endl;
		}
		
	}
	return 0;
}
