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
	int t; cin >> t;
	loop(t) {
		int a, b; cin >> a >> b;
		int n = a + b;
		string s; cin >> s;
		bool invalid = false;
		vector<int> rem;
		for (int i = 0; i < n/2; i++) {
			if (s[i] == '0' && s[n - (i + 1)] == '0') {
				a -= 2;
				continue;
			}
			if (s[i] == '1' && s[n - (i + 1)] == '1') {
				b -= 2;
				continue;
			}
			if (s[i] == '0' && s[n - (i + 1)] == '1') {
				invalid = true;
				continue;
			} else if (s[i] == '0' && s[n - (i + 1)] == '?') {
				s[n - (i + 1)] = '0';
				a -= 2;
			} else if (s[i] == '1' && s[n - (i + 1)] == '0') {
				invalid = true;
				continue;
			} else if (s[i] == '1' && s[n - (i + 1)] == '?') {
				s[n - (i + 1)] = '1';
				b -= 2;
			} else if (s[i] == '?' && s[n - (i + 1)] == '0') {
				s[i] = '0';
				a -= 2;
			} else if (s[i] == '?' && s[n - (i + 1)] == '1') {
				s[i] = '1';
				b -= 2;
			} else {
				rem.pb(min(i, n - (i + 1)));
			}
		}
		if (n % 2 == 1) {
			if (s[n/2] == '1') {
				b--;
			} else if (s[n/2] == '0'){
				a--;
			} else if (a % 2 == 1) {
				s[n/2] = '0';
				a--;
			} else {
				s[n/2] = '1';
				b--;
			}
		}
		for (int idx : rem) {
			if (a >= b) {
				s[idx] = '0';
				s[n - (idx + 1)] = '0';
				a -= 2;
			} else {
				s[idx] = '1';
				s[n - (idx + 1)] = '1';
				b -= 2;
			}
		}
		if (a != 0 || b != 0)
			invalid = true;
		if (invalid) {
			cout << -1 << endl;
		} else {
			cout << s << endl;
		}
	}
	return 0;
}
