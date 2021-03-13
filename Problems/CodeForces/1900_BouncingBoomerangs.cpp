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
	int n; cin >> n;
	vector<int> vals(n), ones, other;
	
	vector<PI> ans;
	vector<bool> full(n);
	
	int cur = n - 1;
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
		if (vals[i] == 1)
			ones.pb(i);
		else if (vals[i] == 2 || vals[i] == 3)
			other.pb(i);
	}
	reverse(ones.begin(), ones.end());
	reverse(other.begin(), other.end());
	bool pos = true;
	for (int i = 0; i < n; i++) {
		if (vals[i] == 0)
			continue;
		
		while (!other.empty() && other.back() <= i)
			other.pop_back();
		
		while (!ones.empty() && ones.back() <= i)
			ones.pop_back();
		
		if (vals[i] == 2) {
			if (ones.empty()) {
				pos = false;
				break;
			}
			int one = ones.back();
			ones.pop_back();
			ans.pb(make_pair(cur, i));
			ans.pb(make_pair(cur, one));
			full[one] = true;
			cur--;
		} else if (vals[i] == 1) {
			if (full[i])
				continue;
			ans.pb(make_pair(cur, i));
			cur--;
		} else {
			if (other.empty() && ones.empty()) {
				pos = false;
				break;
			}
			if (!other.empty()) {
				int two = other.back();
				other.pop_back();
				ans.pb(make_pair(cur, i));
				ans.pb(make_pair(cur, two));
			} else {
				int one = ones.back();
				ones.pop_back();
				ans.pb(make_pair(cur, i));
				ans.pb(make_pair(cur, one));
			}
			cur--;
		}
	}
	if (cur < -1 || !pos) {
		cout << -1 << endl;
	} else {
		cout << (int) ans.size() << endl;
		for (PI val : ans) {
			int row = n - val.first;
			int col = val.second + 1;
			cout << row << " " << col << endl;
		}
	}
	return 0;
}
