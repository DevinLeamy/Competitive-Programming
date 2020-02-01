#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> a; vector<int> b; int n, q, r; cin >> q >> n;
	loop(n) {cin >> r; a.pb(r);}
	loop(n) {cin >> r; b.pb(r);}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (q == 1) {
		int min_ = 0;
		loop(n) { min_ += max(a[i], b[i]);}
		cout << min_ << endl;
	} else {
		int max_ = 0;
		loop(n) { max_ += max(a[i], b[(n-1)-i]); }
		cout << max_ << endl;
	}
	return 0;
}
