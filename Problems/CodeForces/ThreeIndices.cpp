
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
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
		}
		bool found = false;
		for (int i = 0; i < n-2; i++) {
			int cur = vals[i];
			int max = vals[i+1];
			PI good = { i + 1, -1 };
			for (int j = i+1; j < n; j++) {
				if (vals[j] < max && max > cur) {
					good.second = j;
					break;
				}
				if (vals[j] > max) {
					good.first = j;
					max = vals[j];
				}
			}
			if (good.second != -1) {
				found = true;
				cout << "YES\n";
				cout << i + 1 << " " << good.first + 1 << " " << good.second + 1 << endl;
				break;
			}
		}
		if (!found) {
			cout << "NO\n";
		}
	}
	return 0;
}
