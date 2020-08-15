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
	int n, m; cin >> n >> m;
	vector<vector<bool>> val1;
	vector<vector<bool>> val2;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		int cur = 9;
		val1.pb(vector<bool>(10));
		while (a != 0) {
			if (a >= pow(2, cur)) {
				val1[i][cur] = true;
				a -= pow(2, cur);
			} else {
				val1[i][cur] = false;
			}
			cur--;
		}
		
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		int cur = 9;
		val2.pb(vector<bool>(10));
		while (a != 0) {
			if (a >= pow(2, cur)) {
				val2[i][cur] = true;
				a -= pow(2, cur);
			} else {
				val2[i][cur] = false;
			}
			cur--;
		}
		
	}
	int best = pow(2, 9) - 1;
	for (int i = 0; i < pow(2, 9); i++) {
		vector<bool> match(10);
		bool works = true;
		int val = i;
		int cur = 9;
		while (val != 0) {
			if (val >= pow(2, cur)) {
				match[cur] = true;
				val -= pow(2, cur);
			}
			cur--;
		}
		for (int j = 0; j < n; j++) {
			bool found = false;
			for (int l = 0; l < m; l++) {
				bool flag = true;
				for (int k = 0; k < 10; k++) {
					if (val1[j][k] && val2[l][k] && !match[k]) {
						flag = false;
						break;
					}
				}
				if (flag) found = true;
			}
			if (!found) {
				works = false;
			}
		}
		if (works) {
			best = i;
			break;
		}
	}
	cout << best << endl;
	return 0;
}
