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
#define view2(a, b) cout << "DEBUG: " << a << " " << b << endl;
using namespace std;
char _;

vector<int> solve() {
	int n; cin >> n;
	vector<int> vals(n);
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	for (int i = 0; i < n; i++) {
		if (vals[i] < 0)
			return {};
	}
	vector<int> ans(101);
	for (int i = 0; i <= 100; i++)
		ans[i] = i;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		vector<int> ans = solve();
		if (ans.empty()) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			cout << (int) ans.size() << "\n";
			for (int val : ans)
				cout << val << " ";
			cout << "\n";
		}
	}
	return 0;
}
