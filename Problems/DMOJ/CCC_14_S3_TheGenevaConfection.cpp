#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, n, v; cin >> t;
	loop(t) {
		cin >> n;
		int current = 1;
		vector<int> top; vector<int> side;
		for (int j = 0; j < n; j++) {
			cin >> v; top.pb(v);
		}
		bool possible = true;
		while (current != n) {
			if (top.size() > 0 && top.back() == current) {
				top.pop_back();
				current++;
			} else if (side.size() > 0 && side.back() == current) {
				side.pop_back(); current++;
			} else {
				if (top.size() == 0) {
					possible = false;
					break;
				}
				side.pb(top.back()); top.pop_back();
			}
		}
		if (possible) {
			cout << "Y" << endl;
		} else {
			cout << "N" << endl;
		}
	}
	return 0;
}
