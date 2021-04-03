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

bool solve() {
	int n; cin >> n;
	string a, b; cin >> a >> b;
	if (a == b)
		return true;
	int changes = 0;
	vector<bool> can_change(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '1')
			cnt++;
		else
			cnt--;
		if (cnt == 0)
			can_change[i] = true;
	}
	for (int i = n - 1; i >= 0; i--) {
		bool one = a[i] == '1';
		bool oone = b[i] == '1';
		if (changes % 2 == 1)
			one = !one;
		if (one != oone) {
			if (!can_change[i])
				return false;
			changes++;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		if (solve())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
