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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, val; cin >> n;
	string op;
	int cnt = 0;
	vector<pair<bool, int>> seq;
	for (int i = 0; i < 2*n; i++) {
		cin >> op;
		if (op == "-") {
			cin >> val;
			if (cnt != 0) {
				seq.pb({true, cnt});
				cnt = 0;
			}
			seq.pb({false, val});
		} else {
			cnt++;
		}
	}
	vector<int> next(n+1);
	vector<int> ans(n, -1);
	for (int i = 1; i <= n; i++) next[i] = i;
	if (cnt != 0) {
		seq.pb({true, cnt});
		cnt = 0;
	}
	int shelf = 0;
	int any = 0;
	queue<pair<int, PI>> mins;
	for (pair<bool, int> op : seq) {
		bool add = op.first;
		if (add) {
			int cnt = op.second;
			shelf += cnt;
			any += cnt;
		} else {
			int val = op.second;
			if (shelf == 0) {
				cout << "NO\n";
				return 0;
			}
			if (any == 0) {
				int index = mins.back().first;
				int cur_min = mins.back().second.first;
				int rem = mins.back().second.second;
				
				if (val < cur_min) {
					cout << "NO\n";
					return 0;
				}
				while (ans[index] != -1) index--;
				ans[index] = val;
				
				if (rem == 0) mins.pop();
				if (!mins.empty())
					mins.back() = { index - 1, { val + 1, rem - 1}};
			} else {
				any--;
				ans[shelf-1] = val;
				if (any > 0) {
					mins.push({shelf-2, {val + 1, any}});
				}
				any = 0;
			}
		}
	}
	cout << "YES\n";
	for (int val : ans) cout << val << " ";
	return 0;
}
