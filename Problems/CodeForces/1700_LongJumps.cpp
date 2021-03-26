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
	int n; ll l, x, y;
	cin >> n >> l >> x >> y;
	vector<ll> marks(n);
	for (int i = 0; i < n; i++)
		cin >> marks[i];
	
	bool has_x = false, has_y = false;
	ll d_seg = LINF;
	set<ll> dist;
	for (int i = 0; i < n; i++) {
		if (binary_search(marks.begin(), marks.end(), marks[i] + x))
			has_x = true;
		if (binary_search(marks.begin(), marks.end(), marks[i] + y))
			has_y = true;
		if (binary_search(marks.begin(), marks.end(), marks[i] + x + y))
			d_seg = marks[i];
		if (dist.find(marks[i] + x) != dist.end())
			d_seg = marks[i];
		if (marks[i] + y <= l)
			dist.insert(marks[i] + y);
	}
	dist.clear();
	for (int i = n - 1; i >= 0; i--) {
		if (dist.find(marks[i] - x) != dist.end())
			d_seg = marks[i] - 2 * x;
		if (marks[i] - y >= 0)
			dist.insert(marks[i] - y);
	}
	if (has_x && has_y) {
		cout << "0" << endl;
	} else if (has_x) {
		cout << "1" << endl;
		cout << y << endl;
	} else if (has_y) {
		cout << "1" << endl;
		cout << x << endl;
	} else if (d_seg != LINF) {
		cout << "1" << endl;
		cout << d_seg + x << endl;
	} else {
		cout << "2" << endl;
		cout << x << " " << y << endl;
	}
	return 0;
}
