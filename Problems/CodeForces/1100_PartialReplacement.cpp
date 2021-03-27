#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
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
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector<int> pos;
		for (int i = 0; i < n; i++) {
			if (s[i] == '*') {
				pos.pb(i);
			}
		}
		if (pos.empty()) {
			cout << "0" << endl;
		} else if (pos.size() == 1) {
			cout << "1" << endl;
		} else {
			int cnt = 2;
			int cur = pos.front();
			int idx = 0;
			while (cur + k < pos.back()) {
				while (cur + k >= pos[idx + 1])
					idx++;
				cur = pos[idx];
				cnt++;
			}
			cout << cnt << endl;
		}
	}
	return 0;
}
