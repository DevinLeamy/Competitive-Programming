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

int query(int a, int b) {
	if (a >= b)
		return -1;
	cout.flush();
	cout << "? " << a << " " << b << endl;
	int res; cin >> res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	int l = 1, r = n + 1;
	while (l < r) {
		int mid = (r + l) / 2;
		int s_max = query(l, r - 1);
		if (s_max < mid) {
			if (s_max == query(l, mid - 1)) {
				r = mid;
			} else {
				l = mid;
			}
		} else {
			if (s_max == query(mid, r - 1)) {
				l = mid;
			} else {
				r = mid;
			}
		}
	}
	printf("! %d\n", r);
	return 0;
}
