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

const string alphabet = "abcdefghijklmnopqrstuvwxyz";
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		string s; cin >> s;
		int n; cin >> n;
		vector<int> vals(n);
		for (int i = 0; i < n; i++) cin >> vals[i];
		vector<int> letters(26);
		for (int i = 0; i < s.length(); i++) {
			letters[s[i] - 'a']++;
		}
		string ans(n, '1');
		int covered = 0;
		int letter = 25;
		while (covered < n) {
			int zeros = 0;
			for (int j = 0; j < n; j++) {
				if (vals[j] == 0 && ans[j] == '1') {
					zeros++;
				}
			}
			while (letter >= 0 && letters[letter] < zeros) {
				letter--;
			}
			vector<int> newVals(vals);
			for (int j = 0; j < n; j++) {
				if (vals[j] == 0 && ans[j] == '1') {
					ans[j] = alphabet[letter];
					for (int k = 0; k < n; k++) {
						if (vals[k] > 0 && ans[k] == '1') {
							newVals[k] -= abs(k - j);
						}
					}
				}
			}
			vals = newVals;
			covered += zeros;
			letter--;
		}
		cout << ans << endl;
	}
	return 0;
}
