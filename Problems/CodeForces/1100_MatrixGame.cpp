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
		int n, m, a; cin >> n >> m;
		vector<bool> row(n);
		vector<bool> col(m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a;
				if (a == 1) {
					row[i] = true;
					col[j] = true;
				}
			}
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!row[i] && !col[j]) {
					count++;
					row[i] = true;
					col[j] = true;
				}
			}
		}
		if (count % 2 == 0) {
			cout << "Vivek" << endl;
		} else {
			cout << "Ashish" << endl;
		}
	}
	return 0;
}
