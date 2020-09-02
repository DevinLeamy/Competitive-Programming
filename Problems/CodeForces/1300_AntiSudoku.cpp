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
		vector<vector<int>> vals;
		for (int i = 0; i < 9; i++) {
			string s; cin >> s;
			vals.pb(vector<int>(9));
			for (int j = 0; j < 9; j++) {
				vals[i][j] = s[j] - '0';
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (vals[i][j] == 1 || vals[i][j] == 2) {
					cout << 1;
				} else {
					cout << vals[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}
