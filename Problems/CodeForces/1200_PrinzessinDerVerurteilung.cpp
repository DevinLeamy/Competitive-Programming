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

string alph = "abcdefghijklmnopqrstuvwxyz";
string solve() {
	int n; cin >> n;
	string s; cin >> s;
	vector<string> cur;
	for (int i = 0; i < 26; i++)
		cur.pb(string(1, alph[i]));
	for (int i = 0; i < 3; i++) {
		for (string val : cur) {
			bool good = true;
			for (int j = 0; j < n - i; j++) {
				bool match = true;
				for (int k = 0; k < i + 1; k++) {
					if (val[k] != s[j + k]) {
						match = false;
					}
				}
				if (match) {
					good = false;
					break;
				}
			}
			if (good)
				return val;
		}
		vector<string> new_cur;
		for (string val : cur) {
			for (int j = 0; j < 26; j++) {
				new_cur.pb(val + string(1, alph[j]));
			}
		}
		swap(cur, new_cur);
	}
	return "";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		cout << solve() << "\n";
	}
	return 0;
}
