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
	vector<PL> segs(n);
	vector<ll> left(n), right(n);
	for (int i = 0; i < n; i++) {
		cin >> segs[i].first >> segs[i].second;
		left[i] = segs[i].first;
		right[i] = segs[i].second;
	}
		
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	
	int largest = 0;
	for (PI seg: segs) {
		ll a = seg.first, b = seg.second;
		int front = (int) (lower_bound(right.begin(), right.end(), a) - right.begin());
		int back = (int) (upper_bound(left.begin(), left.end(), b) - left.begin());
		largest = max(largest, back - front);
	}
	return n - largest;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		printf("%d\n", solve());
	}
	return 0;
}
