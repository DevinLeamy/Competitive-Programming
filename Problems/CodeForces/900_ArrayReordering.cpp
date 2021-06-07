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

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll solve() {
	int n; cin >> n;
	vector<int> vals;
	int next = n - 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a % 2 == 0) {
			ans += next;
			next--;
		} else {
			vals.pb(a);
		}
	}
	sort(vals.rbegin(), vals.rend());
	for (int i = 0; i < (int) vals.size(); i++) {
		for (int j = i + 1; j < (int) vals.size(); j++) {
			if (gcd(vals[i], vals[j] * 2) > 1)
				ans++;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		cout << solve() << "\n";
	}
	return 0;
}
