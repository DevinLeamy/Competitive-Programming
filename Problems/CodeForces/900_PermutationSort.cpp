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

int solve() {
	int n; cin >> n;
	vector<int> vals(n);
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}
	bool sorted = true;
	for (int i = 1; i < n; i++) {
		sorted &= vals[i] > vals[i - 1];
	}
	if (sorted)
		return 0;
	if (vals[0] == n && vals.back() == 1)
		return 3;
	if (vals[0] == 1 || vals.back() == n)
		return 1;
	return 2;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		cout << solve() << "\n";
	}
	return 0;
}
