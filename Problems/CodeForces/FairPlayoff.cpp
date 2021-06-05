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

bool solve() {
	vector<int> vals(4);
	for (int i = 0; i < 4; i++)
		cin >> vals[i];
	vector<int> no_sorted(vals);
	sort(vals.begin(), vals.end());
	int m1 = vals[3], m2 = vals[2];
	int w1 = max(no_sorted[0], no_sorted[1]);
	int w2 = max(no_sorted[2], no_sorted[3]);
	if ((m1 == w1 && m2 == w2) || (m2 == w1 && m1 == w2))
		return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		if (solve())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
