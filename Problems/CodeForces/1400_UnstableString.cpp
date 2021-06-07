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

ll solve() {
	string s; cin >> s;
	int n = (int) s.length();
	ll ans = 0;
	int prev_stable = 0;
	int prev_marks = 0; // previous question marks
	char last = '?';
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			prev_stable++;
			ans += prev_stable;
			prev_marks++;
			if (last != '?') {
				last = (last == '0')? '1' : '0';
			}
		} else if (s[i] == '0') {
			if (last == '0')
				prev_stable = prev_marks;
			prev_stable++;
			ans += prev_stable;
			last = s[i];
			prev_marks = 0;
		} else {
			if (last == '1')
				prev_stable = prev_marks;
			prev_stable++;
			ans += prev_stable;
			last = s[i];
			prev_marks = 0;
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
