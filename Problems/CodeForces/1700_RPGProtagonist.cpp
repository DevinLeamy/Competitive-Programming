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

ll p, f;
ll s, a;
ll w1, w2;

bool func(int numberOfItems) {
	int small = min((int)s, numberOfItems);
	int large = min((int)a, max(0, numberOfItems - small));
	bool works = false;
	for (int i = 0; i <= small; i++) {
		ll rem = p - i*w1;
		if (rem < 0) continue;
		ll rem2 = f - (small-i)*w1;
		if (rem2 < 0) continue;
		rem2 -= (large - (rem / w2))*w2;
		if (rem2 < 0) continue;
		works = true;
	}
	return works;
}

int binarySearch(int low, int high) {
	if (high - 2 <= low) return low;
	int mid = (low + high)/2;
	if (func(mid)) {
		return binarySearch(mid, high);
	}
	return binarySearch(low, mid-1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		cin >> p >> f;
		vector<int> vals;
		cin >> s >> a;
		cin >> w1 >> w2;
		if (w1 >= w2) {
			ll temp1 = s;
			ll temp2 = w1;
			w1 = w2;
			s = a;
			a = temp1;
			w2 = temp2;
		}
		int low = binarySearch(0, s + a);
		while (func(low + 1) && low != s + a) {
			low++;
		}
		cout << low << endl;
		
	}
	return 0;
}
